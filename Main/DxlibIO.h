#pragma once
#include "IOBase.h"
#include "DxLib.h"

class DxlibIO : public IOBase
{
public:
	DxlibIO();
	~DxlibIO();
	int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness);
	int GetMousePoint(int *XBuf, int *YBuf);
	bool MouseLeftClicked(void);
	bool MouseRightClicked(void);
	int GetMouseWheelRotVol();
};