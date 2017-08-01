#include "LSystemView.h"

LSystemView::LSystemView(IOBase *io, LSystem *lsystem) : io_(io), lsystem_(lsystem)
{
	scale_ = 7;
	initx_ = 600;
	inity_ = 360;
}

LSystemView::~LSystemView()
{
}

LSystemView & LSystemView::SetScale(const int scale)
{
	if (scale > 1) {
		scale_ = scale;
	}
	else {
		// Žw’è‚ª¬‚³‚·‚¬‚éê‡AÅ¬’l‚Ü‚Åk¬
		scale_ = 2;
	}
	return *this;
}

void LSystemView::Draw(const int ticks)
{
	for (DrawParts *parts : lsystem_->CreateDrawParts(ticks)) {
		parts->Draw(io_, initx_, inity_, scale_);
		delete parts;
	}
}
