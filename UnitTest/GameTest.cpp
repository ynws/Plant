#include "MockIO.h"
#include "Game.h"

class GameTest : public ::testing::Test
{
protected:
	MockIO mock;
	LSystem model;
	LSystemView view;
	Game controller;
	virtual void SetUp() { }
	virtual void TearDown() { }
public:
	GameTest() : model("F"), view(&mock, &model), controller(&mock, &view, &model) {};
};

TEST_F(GameTest, ZoomIn) {
	view.SetScale(10);
	// �}�E�X�z�C�[����]�ɂ��View���g�傷��
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(1));
	controller.Update();
	ASSERT_EQ(view.GetScale(), 15);
}

TEST_F(GameTest, ZoomOut) {
	view.SetScale(10);
	// �}�E�X�z�C�[����]�ɂ��View���k������
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(-1));
	controller.Update();
	ASSERT_EQ(view.GetScale(), 5);
}

TEST_F(GameTest, NoZoom) {
	view.SetScale(10);
	// �}�E�X�z�C�[����]�Ȃ�
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(0));
	controller.Update();
	ASSERT_EQ(view.GetScale(), 10);
}

// Update��2��ĂсAView�̈ʒu�𓮂����B
TEST_F(GameTest, ViewMove) {
	// 2��Ƃ����N���b�N���Ă���
	EXPECT_CALL(mock, MouseLeftClicked())
		.Times(2)
		.WillRepeatedly(Return(true));
	// ���ꂼ��̃}�E�X�ʒu��ݒ�
	EXPECT_CALL(mock, GetMousePoint(_, _))
		.Times(2)
		.WillOnce(DoAll(SetArgPointee<0>(20), SetArgPointee<1>(30), Return(0)))
		.WillOnce(DoAll(SetArgPointee<0>(30), SetArgPointee<1>(10), Return(0)));

	view.SetInitX(10).SetInitY(10);
	controller.Update();	// ����}�E�X�ʒu���L�^
	controller.Update();	// ���ɌĂ΂ꂽ�Ƃ��}�E�X�̂��ꕪ�����ړ�
	ASSERT_EQ(view.GetInitX(), 20);
	ASSERT_EQ(view.GetInitY(), -10);
}
