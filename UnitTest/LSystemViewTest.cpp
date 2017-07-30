#include "MockIO.h"
#include "LSystemView.h"

TEST(LSview, Draw)
{
	MockIO mock;
	LSystem model("a", "a", "abc");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(1, 2, 3, 4, 5, 6)).Times(1);
	view.Draw();
}
