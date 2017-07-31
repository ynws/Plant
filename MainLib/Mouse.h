#pragma once
#include "IOBase.h"

// ユーザのマウス入力を管理するクラス
class Mouse
{
private:
	int x_, y_, left_, right_, wheel_;
	int old_x_, old_y_;
	IOBase *io_;
public:
	Mouse(IOBase *io);
	~Mouse();
	void Update();
	const int GetX() { return x_; };
	const int GetY() { return y_; };
	const int GetDx() { return x_ - old_x_; };
	const int GetDy() { return y_ - old_y_; };
	const int GetWheel() { return wheel_; }
	const bool IsLeftClicked() { return left_ == 1; } // 左ボタンのクリック
	const bool IsLeftPressed() { return left_ > 1; } // 左ボタンを長押ししているか
};

