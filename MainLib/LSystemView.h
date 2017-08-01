#pragma once
#include "IOBase.h"
#include "LSystem.h"

class LSystemView
{
private:
	IOBase *io_;
	LSystem *lsystem_;
	int scale_;
	int initx_;
	int inity_;
public:
	LSystemView(IOBase *io, LSystem *lsystem);
	~LSystemView();
	int GetScale() { return scale_; }
	int GetInitX() { return initx_; }
	int GetInitY() { return inity_; }
	LSystemView& SetScale(const int scale);
	LSystemView& SetInitX(const int initx) { initx_ = initx; return *this; }
	LSystemView& SetInitY(const int inity) { inity_ = inity; return *this; }

	void Draw(int ticks);
};

