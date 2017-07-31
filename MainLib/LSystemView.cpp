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
		// �w�肪����������ꍇ�A�ŏ��l�܂ŏk��
		size_ = 2;
	}
	return *this;
}

void LSystemView::Draw(const int ticks)
{
	// ���ݏ�Ԃ�\���\���́B'[', ']'�ŃX�^�b�N�ɏ�Ԃ�ۑ�����
	struct status {
		double x;
		double y;
		double angle;
	};
	std::vector<status> stack;
	status st = { (double)initx_, (double)inity_, 90.0 }; // �����p�x��90�x�ŏ����

	std::string str = lsystem_->GetString(ticks);
	// TODO: ���������ɑΉ�
	for (size_t i = 0; i < str.length(); i++) {
		double nextx = st.x + (size_*cos(st.angle*PI / 180));
		double nexty = st.y - (size_*sin(st.angle*PI / 180));
		switch (str[i]) {
		case 'F':	// ���������Ȃ���i��
		case 'A':
		case 'B':
			io_->DrawLine((int)st.x, (int)st.y, (int)nextx, (int)nexty, 0, 1);
			st.x = nextx;
			st.y = nexty;
			break;
		case 'f':	// �ړ�����
			st.x = nextx;
			st.y = nexty;
			break;
		case '+':	// ���ɉ�]
			st.angle += angle_;
			break;
		case '-':	// �E�ɉ�]
			st.angle -= angle_;
			break;
		case '[': // ��ԁi�ʒu�ƌ����j���X�^�b�N�Ƀv�b�V��
			stack.push_back(st);
			break;
		case ']': // ��Ԃ��X�^�b�N����|�b�v
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
