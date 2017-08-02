#pragma once
#include <string>
#include <vector>
#include "DrawParts.h"

class LSystem
{
private:
	struct Rule
	{
		char from;	// TODO: �����������������ɑΉ�
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
	// �`�ʑΏۃp�[�c�Q��Ԃ�
	// �p�[�c��delete�͌Ăяo�����Ƃōs������
	std::vector<DrawParts*> CreateDrawParts(const int ticks);
};
