#include "MockIO.h"
#include "LSystemView.h"

using ::testing::_; // 任意の引数

TEST(LSview, Draw)
{
	MockIO mock;
	// 真上に進んで、左回転して1歩進んだ後右回転して真上に進む
	LSystem model("F+f-F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(1);
	EXPECT_CALL(mock, DrawLine(593, 352, 593, 345, 0, 1)).Times(1);
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
