#include "LiderBoard.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void LiderBoard::AddPlayer(Player& player)
{
	Players.push_back(player);
}
void LiderBoard::PrintFile(Player& player) 
{
	std::ofstream out;
	out.open("liderboard.txt", std::ios::app);
	if (out.is_open())
	{
		out << player.GetName() << " " << player.GetNum();
	}
	out.close();
}
void LiderBoard::GetFile()
{
	std::ifstream in("liderboard.txt");
	Player pl;
	if (in.is_open()) {
		std::string t;
		int nums;
		while (in >> t >> nums)
		{
			pl.Set(t,nums);
			Players.push_back(pl);
		}
	}
}
std::string LiderBoard::TextRetunr()
{
	std::string text;
	for (int i = 0; i < Players.size(); i++)
	{
		std::stringstream ss;
		ss << Players[i].GetNum();
		text += (std::string)Players[i].GetName() + " -  " + ss.str() + "\n";
	}
	return text;
}