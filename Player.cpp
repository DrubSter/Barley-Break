#include "Player.h"
Player::Player()
{
	name = new char[20];
	num = 0;
}
Player::Player(char* name, int num)
{
	this->name = name;
	this->num = num;
}
Player::~Player()
{
	delete[] name;
}
void Player::Set(char* name, int num)
{
	delete[] this->name;
	this->name = name;
	this->num = num;
}
char* Player::GetName()
{
	return name;
}
int Player::GetNum()
{
	return this->num;
}