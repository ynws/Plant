#include "MockIO.h"
#include "Game.h"

using ::testing::Return;

TEST(Game, ZoomIn) {
	MockIO mock;
	LSystem model("F");
	LSystemView view(&mock, &model);
	Game controller(&mock, &view, &model);

	view.SetStepSize(10);
	// �}�E�X�z�C�[����]�ɂ��View���g�傷��
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(1));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 15);
}

TEST(Game, ZoomOut) {
	MockIO mock;
	LSystem model("F");
	LSystemView view(&mock, &model);
	Game controller(&mock, &view, &model);

	view.SetStepSize(10);
	// �}�E�X�z�C�[����]�ɂ��View���k������
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(-1));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 5);
}

TEST(Game, NoZoom) {
	MockIO mock;
	LSystem model("F");
	LSystemView view(&mock, &model);
	Game controller(&mock, &view, &model);

	view.SetStepSize(10);
	// �}�E�X�z�C�[����]�Ȃ�
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(0));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 10);
}
