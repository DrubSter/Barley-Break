#pragma once
#include "Player.h"
#include <fstream>
class LiderBoard
{
	Player* Players;
	float nums;
public:
	LiderBoard();
	~LiderBoard();
	void PrintFile();
	void GetFile();
};

