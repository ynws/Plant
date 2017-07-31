#include <math.h>
#include "LSystemView.h"

#define PI 3.14159265

LSystemView::LSystemView(IOBase *io, LSystem *lsystem) : io_(io), lsystem_(lsystem)
{
	size_ = 7;
	angle_ = 90;
	initx_ = 600;
	inity_ = 360;
}

LSystemView::~LSystemView()
{
}

LSystemView & LSystemView::SetStepSize(const int size)
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

void LSystemView::Draw(const int ticks)
{
	// 現在状態を表す構造体。'[', ']'でスタックに状態を保存する
	struct status {
		double x;
		double y;
		double angle;
	};
	std::vector<status> stack;
	status st = { (double)initx_, (double)inity_, 90.0 }; // 初期角度は90度で上向き

	std::string str = lsystem_->GetString(ticks);
	// TODO: 複数文字に対応
	for (size_t i = 0; i < str.length(); i++) {
		double nextx = st.x + (size_*cos(st.angle*PI / 180));
		double nexty = st.y - (size_*sin(st.angle*PI / 180));
		switch (str[i]) {
		case 'F':	// 線を書きながら進む
		case 'A':
		case 'B':
			io_->DrawLine((int)st.x, (int)st.y, (int)nextx, (int)nexty, 0, 1);
			st.x = nextx;
			st.y = nexty;
			break;
		case 'f':	// 移動だけ
			st.x = nextx;
			st.y = nexty;
			break;
		case '+':	// 左に回転
			st.angle += angle_;
			break;
		case '-':	// 右に回転
			st.angle -= angle_;
			break;
		case '[': // 状態（位置と向き）をスタックにプッシュ
			stack.push_back(st);
			break;
		case ']': // 状態をスタックからポップ
			if (stack.size()) {
				st = stack.back();
				stack.pop_back();
			}
			break;
		default:
			break;
		}
	}
}
