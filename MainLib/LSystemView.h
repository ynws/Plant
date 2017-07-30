#pragma once
#include "LSystem.h"
class LSystemView
{
private:
	LSystem *lsystem_;
	int size_;
	int angle_;
	int initx_;
	int inity_;
public:
	LSystemView(LSystem *lsystem);
	~LSystemView();
	void SetStepSize(int size) { size_ = size; }
	void SetAngle(int angle) { angle_ = angle; }
	void SetInitX(int initx) { initx_ = initx; }
	void SetInitY(int inity) { inity_ = inity; }
	void Draw();
};

