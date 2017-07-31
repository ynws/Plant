#include "Mouse.h"

Mouse::Mouse(IOBase * io) : io_(io)
{
	x_ = y_ = left_ = right_ = wheel_ = 0;
	old_x_ = old_y_ = 0;
}

Mouse::~Mouse()
{
}

// �}�E�X�̓��͏����X�V
void Mouse::Update()
{
	// �ʒu���X�V
	old_x_ = x_;
	old_y_ = y_;
	io_->GetMousePoint(&x_, &y_);

	// �}�E�X�z�C�[���̉�]���
	wheel_ = io_->GetMouseWheelRotVol();

	// �N���b�N���(�������ɑΉ����邽�߁A�Ăяo����邽�тɃC���N�������g)
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
