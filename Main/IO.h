#pragma once
#include "IOStatus.h"

class IO
{
private:
public:
	virtual ~IO() {};
	virtual eCursor GetCursorInput(int InputType) = 0;
	virtual int DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag, int LineThickness) = 0;
};