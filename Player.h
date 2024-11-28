#pragma once
class Player
{
	char* name;
	int num = 0;
public:

	Player();
	Player(char* name, int num);
	~Player();
	void Set(char* name, int num);
	char* GetName();
	int GetNum();
};

