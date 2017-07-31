#pragma once
#include "LSystemView.h"
#include "Mouse.h"

class Game
{
private:
	IOBase *io_;
	LSystemView *view_;
	LSystem *lsystem_;
	Mouse mouse_;
public:
	Game(IOBase *io, LSystemView *lsystemview, LSystem *lsystem);
	void Update();
};