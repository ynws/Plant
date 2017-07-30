#pragma once

class IOBase
{
public:
	virtual ~IOBase() {};
	virtual int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness) = 0;
	virtual int GetMousePoint(int *XBuf, int *YBuf) = 0;
	virtual int GetMouseInput(void) = 0;
	virtual int GetMouseWheelRotVol() = 0;
};
