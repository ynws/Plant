#include <math.h>
#include "LSystem.h"
#include "Line.h"

#define PI 3.14159265

LSystem::LSystem(const std::string& init_string) : init_string_(init_string), angle_(90.0)
{
}

LSystem::~LSystem()
{
}

LSystem & LSystem::SetAngle(const double angle)
{
	angle_ = angle;
	return *this;
}

LSystem& LSystem::SetInitialString(const std::string& str)
{
	init_string_ = str;
	return *this;
}

LSystem& LSystem::AddRule(const std::string& from, const std::string& to)
{
	Rule rule{ from.c_str()[0], to };
	rules.push_back(rule);
	return *this;
}

void LSystem::ClearRule()
{
	rules.clear();
}

std::string LSystem::GetString(const int ticks)
{
	std::string ret = init_string_;
	for (int t = 0; t < ticks; t++) {
		std::string buf;
		// TODO: �v���ǁB���̂������o�J���ۂ����[�v���񂵂Ă���C������
		for (int i = 0; i < (int)ret.size(); ++i) {
			char c = ret[i];
			bool hit = false;
			for (Rule& rule : rules) {
				if (c == rule.from) {
					buf.append(rule.to);
					hit = true;
					break;
				}
			}
			if (!hit)buf.push_back(c);
		}
		ret = buf;
	}
	return ret;
}

std::vector<DrawParts*> LSystem::CreateDrawParts(const int ticks)
{
	std::vector<DrawParts*> ret;
	// ���ݏ�Ԃ�\���\���́B'[', ']'�ŃX�^�b�N�ɏ�Ԃ�ۑ�����
	struct status {
		double x;
		double y;
		double angle;
	};
	std::vector<status> stack;
	status st = { 0.0, 0.0, 90.0 }; // �����p�x��90�x�ŏ����

	std::string str = GetString(ticks);
	// TODO: ���������ɑΉ�
	for (size_t i = 0; i < str.length(); i++) {
		double nextx = st.x + cos(st.angle*PI / 180);
		double nexty = st.y - sin(st.angle*PI / 180);
		switch (str[i]) {
		case 'F':	// ���������Ȃ���i��
		case 'A':
		case 'B':
			ret.push_back(new Line(st.x, st.y, nextx, nexty));
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
	return ret;
}