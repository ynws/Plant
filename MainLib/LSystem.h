#pragma once
#include <string>
#include <vector>

class LSystem
{
private:
	struct Rule
	{
		char from;	// TODO: �����������������ɑΉ�
		std::string to;
	};
	std::string init_string_;
	std::vector<Rule> rules;
public:
	LSystem(std::string init_string);
	~LSystem();
	void SetInitialString(std::string str);
	void AddRule(std::string from, std::string to);
	void ClearRule();
	std::string GetString(int ticks);
};

