#pragma once

#include "Player.h"


class Knight : public Player
{
public:
	Knight();
	Knight(int hp, int mp, int attack, int exp, int stamina);
	~Knight();

	virtual void TakeDamage(int amount) override;
	virtual void PrintCreature() override;
	virtual int getEXP(int exp) override;

private:
	int _stamina;
};

