#include "MockIO.h"
#include "Game.h"

using ::testing::Return;

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
	view.SetStepSize(10);
	// マウスホイール回転によりViewが拡大する
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(1));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 15);
}

TEST_F(GameTest, ZoomOut) {
	view.SetStepSize(10);
	// マウスホイール回転によりViewが縮小する
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(-1));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 5);
}

TEST_F(GameTest, NoZoom) {
	view.SetStepSize(10);
	// マウスホイール回転なし
	EXPECT_CALL(mock, GetMouseWheelRotVol()).Times(1).WillRepeatedly(Return(0));
	controller.Update();
	ASSERT_EQ(view.GetStepSize(), 10);
}
