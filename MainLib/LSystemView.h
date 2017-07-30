#pragma once
#include "IOBase.h"
#include "LSystem.h"

class LSystemView
{
private:
	IOBase *io_;
	LSystem *lsystem_;
	int size_;
	int angle_;
	int initx_;
	int inity_;
public:
	LSystemView(IOBase *io, LSystem *lsystem);
	~LSystemView();
	int GetStepSize() { return size_; }
	LSystemView& SetStepSize(int size);
	LSystemView& SetAngle(int angle) { angle_ = angle; return *this; }
	LSystemView& SetInitX(int initx) { initx_ = initx; return *this; }
	LSystemView& SetInitY(int inity) { inity_ = inity; return *this; }

	void Draw(int ticks);
};

