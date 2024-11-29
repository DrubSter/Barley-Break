#include "LiderBoard.h"
LiderBoard::LiderBoard()
{

}
LiderBoard::~LiderBoard()
{

}
void LiderBoard::PrintFile() 
{
	std::ofstream out;
	out.open("liderboard.txt");
	if (out.is_open())
	{
		for (int i = 0; i < nums; i++)
		{
			out << Players[i].GetName() << " " << Players[i].GetNum();
		}
	}
	out.close();
}
void LiderBoard::GetFile()
{
	std::ifstream in;
	in.open("liderboard.txt");
	if (in.is_open()) {
		char* txt = new char[20];
		int nums;
		while (in >> txt >> nums)
		{

		}
	}
}