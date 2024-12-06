#pragma once
#include "Player.h"
#include <vector>
#include <fstream>
class LiderBoard
{
	std::vector<Player> Players;
public:
	void AddPlayer(Player& player);
	void PrintFile(Player& player);
	void GetFile();
	std::string TextRetunr();
};

