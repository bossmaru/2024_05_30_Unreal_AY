#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int mp, int attack)
: Creature(name, hp, mp, attack)
, _exp(0)
{
}

Player::~Player()
{
}
