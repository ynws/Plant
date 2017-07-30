#include <math.h>
#include "LSystemView.h"

#define PI 3.14159265

LSystemView::LSystemView(IOBase *io, LSystem *lsystem)
{
	io_ = io;
	lsystem_ = lsystem;
	size_ = 7;
	angle_ = 90;
	initx_ = 600;
	inity_ = 360;
}

LSystemView::~LSystemView()
{
}

LSystemView & LSystemView::SetStepSize(int size)
{
	if (size > 1) {
		size_ = size;
	}
	else {
		// 指定が小さすぎる場合、最小値まで縮小
		size_ = 2;
	}
	return *this;
}

void LSystemView::Draw(int ticks)
{
	double x = initx_;
	double y = inity_;
	int angle = 90;	// 上向き(Dxlibでは、yがマイナスされる方向)

	std::string str = lsystem_->GetString(ticks);
	// TODO: 複数文字に対応
	for (size_t i = 0; i < str.length(); i++) {
		double nextx = x + (size_*cos(angle*PI / 180));
		double nexty = y - (size_*sin(angle*PI / 180));
		switch (str[i]) {
		case 'F':	// 線を書きながら進む
		case 'A':
		case 'B':
			io_->DrawLine((int)x, (int)y, (int)nextx, (int)nexty, 0, 1);
			x = nextx;
			y = nexty;
			break;
		case 'f':	// 移動だけ
			x = nextx;
			y = nexty;
			break;
		case '+':	// 左に回転
			angle += angle_;
			break;
		case '-':	// 右に回転
			angle -= angle_;
			break;
		default:
			break;
		}
	}
}
