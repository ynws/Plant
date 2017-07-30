#include "MockIO.h"
#include "Game.h"

using ::testing::Return;

TEST(Game, ZoomIn) {
	MockIO mock;
	LSystem model("F");
	LSystemView view(&mock, &model);
	Game controller(&mock, &view, &model);

	view.SetStepSize(10);
	// マウスホイール回転によりViewが拡大する
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
	// マウスホイール回転によりViewが縮小する
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
	// マウスホイール回転なし
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(0));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 10);
}
