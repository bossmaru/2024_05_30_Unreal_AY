#include "pch.h"
#include "Player.h"

Player::Player()
{
	_exp = 0;
}

Player::Player(int hp, int mp, int attack, int exp)
: Creature(hp, mp, attack)
{
	_exp = exp;
}

Player::~Player()
{
}

int Player::getEXP(int exp)
{
	return 0;
}
