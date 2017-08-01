#pragma once
#include <string>
#include <vector>
#include "DrawParts.h"

class LSystem
{
private:
	struct Rule
	{
		char from;	// TODO: こっちも複数文字に対応
		std::string to;
	};
	double angle_;
	std::string init_string_;
	std::vector<Rule> rules;
public:
	LSystem(const std::string& init_string);
	~LSystem();
	LSystem& SetAngle(const double angle);
	LSystem& SetInitialString(const std::string& str);
	LSystem& AddRule(const std::string& from, const std::string& to);
	void ClearRule();
	std::string GetString(const int ticks);
	// 描写対象パーツ群を返す
	// パーツのdeleteは呼び出しもとで行うこと
	std::vector<DrawParts*> CreateDrawParts(const int ticks);
};
