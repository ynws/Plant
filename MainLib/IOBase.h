#pragma once

class IOBase
{
public:
	virtual ~IOBase() {};
	virtual int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness) = 0;
};
