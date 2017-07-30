#include "MockIO.h"
#include "Game.h"

TEST(Game, init) {
	MockIO mock;
	LSystem model("F-F-F-F", "F", "F-F+F+FF-F-F+F");
	LSystemView view(&mock, &model);
	Game controller(&view, &model);
	controller.Update();
}
