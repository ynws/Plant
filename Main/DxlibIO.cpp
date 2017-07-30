#include "DxlibIO.h"

DxlibIO::DxlibIO()
{
}

DxlibIO::~DxlibIO()
{
}

int DxlibIO::DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness)
{
	return DxLib::DrawLine(x1, y1, x2, y2, Color, Thickness);
}

int DxlibIO::GetMousePoint(int * XBuf, int * YBuf)
{
	return DxLib::GetMousePoint(XBuf, YBuf);
}

int DxlibIO::GetMouseInput(void)
{
	return DxLib::GetMouseInput();
}

int DxlibIO::GetMouseWheelRotVol()
{
	return DxLib::GetMouseWheelRotVol();
}

