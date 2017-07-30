#include <gtest/gtest.h>
#include "Game.h"

TEST(Game, init) {
	LSystem model;
	LSystemView view(&model);
	Game controller(&view, &model);
	controller.Update();
	view.Draw();
}
