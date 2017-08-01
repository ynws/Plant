#pragma once
#include "DrawParts.h"
class Line :
	public DrawParts
{
protected:
	double last_posx_, last_posy_;
public:
	Line(double posx, double posy, double last_posx, double last_posy)
		: DrawParts(posx, posy), last_posx_(last_posx), last_posy_(last_posy) {}

	void Draw(IOBase *io, int initx, int inity, int scale) {
		io->DrawLine(
			initx + (int)(posx_ * scale),
			inity + (int)(posy_ * scale),
			initx + (int)(last_posx_ * scale),
			inity + (int)(last_posy_ * scale),
			0, 1);
	}
};

