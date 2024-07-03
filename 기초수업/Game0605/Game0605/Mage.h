#pragma once

#include "Player.h"


class Mage : public Player
{
public:
	Mage();
	Mage(int hp, int mp, int attack, int exp);
	~Mage();

	virtual void Attack(Creature* c) override;
	virtual int getEXP(int exp) override;
};

