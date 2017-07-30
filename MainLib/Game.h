#pragma once
#include "LSystem.h"
#include "LSystemView.h"

class Game
{
private:
	LSystemView *lsystemview_;
	LSystem *lsystem_;
public:
	Game(LSystemView *lsystemview, LSystem *lsystem);
	void Update();
};