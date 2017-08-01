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
		// TODO: 要改良。ものすごくバカっぽいループを回している気がする
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
	// 現在状態を表す構造体。'[', ']'でスタックに状態を保存する
	struct status {
		double x;
		double y;
		double angle;
	};
	std::vector<status> stack;
	status st = { 0.0, 0.0, 90.0 }; // 初期角度は90度で上向き

	std::string str = GetString(ticks);
	// TODO: 複数文字に対応
	for (size_t i = 0; i < str.length(); i++) {
		double nextx = st.x + cos(st.angle*PI / 180);
		double nexty = st.y - sin(st.angle*PI / 180);
		switch (str[i]) {
		case 'F':	// 線を書きながら進む
		case 'A':
		case 'B':
			ret.push_back(new Line(st.x, st.y, nextx, nexty));
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
	return ret;
}