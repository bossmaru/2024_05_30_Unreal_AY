#pragma once

#include "pch.h"
#include "Creature.h"


class Player : public Creature
{
public:
	Player();
	Player(int hp, int mp, int attack, int exp);
	~Player();

	virtual int getEXP(int exp) abstract;

protected:
	int _exp;
};

