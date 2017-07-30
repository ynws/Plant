#include "LSystemView.h"

LSystemView::LSystemView(IOBase *io, LSystem *lsystem)
{
	io_ = io;
	lsystem_ = lsystem;
}

LSystemView::~LSystemView()
{
}

void LSystemView::Draw()
{
	// test
	io_->DrawLine(1, 2, 3, 4, 5, 6);
}
