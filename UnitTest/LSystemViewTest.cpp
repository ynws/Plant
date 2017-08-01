#include "MockIO.h"
#include "LSystemView.h"

TEST(LSview, Draw)
{
	MockIO mock;
	// 真上に進んで、左回転して1歩進んだ後右回転して真上に進む
	LSystem model("F+f-F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(1);
	EXPECT_CALL(mock, DrawLine(594, 353, 594, 346, 0, 1)).Times(1);
	view.Draw(0);
}

TEST(LSview, SetAngle)
{
	MockIO mock;
	// 左回転して1歩進む
	LSystem model("+F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 593, 360, 0, 1)).Times(1);
	view.Draw(0);

	// 角度指定で逆向きになる
	model.SetAngle(-90.0);
	EXPECT_CALL(mock, DrawLine(600, 360, 607, 360, 0, 1)).Times(1);
	view.Draw(0);
}

TEST(LSview, NotDraw)
{
	MockIO mock;
	LSystem model("+X-");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(_, _, _, _, _, _)).Times(0);
	view.Draw(0);
}

TEST(LSview, SetStepSize)
{
	MockIO mock;
	LSystem model("");
	LSystemView view(&mock, &model);
	view.SetScale(10);
	ASSERT_EQ(view.GetScale(), 10);
	view.SetScale(5);
	ASSERT_EQ(view.GetScale(), 5);
}

TEST(LSview, SetStepSizeMin)
{
	MockIO mock;
	LSystem model("");
	LSystemView view(&mock, &model);
	view.SetScale(10);
	// 指定が小さすぎる場合、最小値までリサイズ
	view.SetScale(1);
	ASSERT_EQ(view.GetScale(), 2);
}

TEST(LSview, Stack)
{
	MockIO mock;
	// 状態保存してから移動。最後に初期状態で描写
	LSystem model("[Ff+]F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(2);
	view.Draw(0);
}

TEST(LSview, StackEmpty)
{
	MockIO mock;
	// 2回目の情報取り出しはできないので、無視する
	LSystem model("[Ff+]]F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(2);
	view.Draw(0);
}
