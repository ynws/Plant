#pragma once
#include "IOBase.h"
#include "LSystem.h"

class LSystemView
{
private:
	IOBase *io_;
	LSystem *lsystem_;
	int size_;
	double angle_;
	int initx_;
	int inity_;
public:
	LSystemView(IOBase *io, LSystem *lsystem);
	~LSystemView();
	int GetStepSize() { return size_; }
	LSystemView& SetStepSize(const int size);
	LSystemView& SetAngle(const double angle) { angle_ = angle; return *this; }
	LSystemView& SetInitX(const int initx) { initx_ = initx; return *this; }
	LSystemView& SetInitY(const int inity) { inity_ = inity; return *this; }

	void Draw(int ticks);
};

