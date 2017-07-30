#pragma once
#include <string>
#include <vector>

class LSystem
{
private:
	struct Rule
	{
		char from;	// TODO: ‚±‚Á‚¿‚à•¡”•¶š‚É‘Î‰
		std::string to;
	};
	std::string init_string_;
	std::vector<Rule> rules;
public:
	LSystem(const std::string& init_string);
	~LSystem();
	LSystem& SetInitialString(const std::string& str);
	LSystem& AddRule(const std::string& from, const std::string& to);
	void ClearRule();
	std::string GetString(const int ticks);
};

