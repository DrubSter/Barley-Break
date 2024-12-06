#pragma once
#include <string>
class Player
{
	std::string name;
	int num = 0;
public:

	Player();
	Player(std::string str, int num);
	void Set(std::string str, int num);
	std::string GetName();
	int GetNum();
};

