#include "LSystem.h"

LSystem::LSystem(std::string init_string)
{
	init_string_ = init_string;
}

LSystem::~LSystem()
{
}

void LSystem::SetInitialString(std::string str)
{
	init_string_ = str;
}

void LSystem::AddRule(std::string from, std::string to)
{
	Rule rule{ from.c_str()[0], to };
	rules.push_back(rule);
}

void LSystem::ClearRule()
{
	rules.clear();
}

std::string LSystem::GetString(int ticks)
{
	std::string ret = init_string_;
	for (int t = 0; t < ticks; t++) {
		std::string buf;
		// ものすごくバカっぽいループを回している気がする
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
