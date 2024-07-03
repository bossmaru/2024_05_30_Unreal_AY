#pragma once

#include "Player.h"

class Archer : public Player
{
public:
	Archer();
	Archer(int hp, int mp, int attack, int exp);
	~Archer();

	virtual void Attack(Creature* c);
	virtual int getEXP(int exp) override;
};

