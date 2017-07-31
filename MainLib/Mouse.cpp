#include "Mouse.h"

Mouse::Mouse(IOBase * io) : io_(io)
{
	x_ = y_ = left_ = right_ = wheel_ = 0;
	old_x_ = old_y_ = 0;
}

Mouse::~Mouse()
{
}

// マウスの入力情報を更新
void Mouse::Update()
{
	// 位置情報更新
	old_x_ = x_;
	old_y_ = y_;
	io_->GetMousePoint(&x_, &y_);

	// マウスホイールの回転状態
	wheel_ = io_->GetMouseWheelRotVol();

	// クリック情報(長押しに対応するため、呼び出されるたびにインクリメント)
	if (io_->MouseLeftClicked()) {
		left_++;
	}
	else {
		left_ = 0;
	}
	if (io_->MouseRightClicked()) {
		right_++;
	}
	else {
		right_ = 0;
	}
}
