#include "DxLib.h"
#include "DxlibIO.h"

DxlibIO::DxlibIO()
{
}

DxlibIO::~DxlibIO()
{
}

eCursor DxlibIO::GetCursorInput(int InputType)
{
	// TODO: “¯Žž‰Ÿ‚µ‘Î‰ž
	int key = DxLib::GetJoypadInputState(InputType);
	if (key & PAD_INPUT_UP) return eCursor::UP;
	if (key & PAD_INPUT_DOWN) return eCursor::DOWN;
	if (key & PAD_INPUT_RIGHT) return eCursor::RIGHT;
	if (key & PAD_INPUT_LEFT) return eCursor::LEFT;
	return eCursor::NONE;
}

int DxlibIO::DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag, int LineThickness)
{
	return DxLib::DrawCircle(x, y, r, Color, FillFlag, LineThickness);
}
