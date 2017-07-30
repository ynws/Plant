#pragma once
#include "LSystemView.h"

class Game
{
private:
	IOBase *io_;
	LSystemView *view_;
	LSystem *lsystem_;
public:
	Game(IOBase *io, LSystemView *lsystemview, LSystem *lsystem);
	void Update();
};