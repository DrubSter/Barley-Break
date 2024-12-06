#include "Player.h"
Player::Player()
{
	name = "";
	num = 0;
}
Player::Player(std::string str, int num)
{
	this->name = str;
	this->num = num;
}
void Player::Set(std::string str, int num)
{
	this->name = str;
	this->num = num;
}
std::string Player::GetName()
{
	return name;
}
int Player::GetNum()
{
	return this->num;
}