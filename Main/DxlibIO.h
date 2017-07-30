#pragma once
#include "IO.h"

// TODO: 以下の定義がダサすぎるのでもっとスマートにしたい
#define TRUE	1
#define FALSE	0

class DxlibIO : public IO
{
public:
	DxlibIO();
	~DxlibIO();
	eCursor GetCursorInput(int InputType);
	int DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag = TRUE, int LineThickness = 1);
};