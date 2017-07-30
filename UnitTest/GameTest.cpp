#include <gtest/gtest.h>
#include "Game.h"

TEST(Game, init) {
	LSystem model("F-F-F-F", "F", "F-F+F+FF-F-F+F");
	LSystemView view(&model);
	Game controller(&view, &model);
	controller.Update();
	view.Draw();
}
