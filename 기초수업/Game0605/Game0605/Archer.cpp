#include "pch.h"
#include "Archer.h"

Archer::Archer()
{
	_type = "Archer";
}

Archer::Archer(int hp, int mp, int attack, int exp)
: Player(hp, mp, attack, exp)
{
	_type = "Archer";
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* c)
{
	srand(time(NULL));
	int percentage = rand() % 10 + 1;
	if (percentage == 1 || percentage == 2 || percentage == 3)
	{
		c->TakeDamage(_attack * 3);
	}
	else
	{
		c->TakeDamage(_attack);
	}
}

int Archer::getEXP(int exp)
{
	_exp += exp;
	_hp += exp / 3;
	_mp += exp / 3;
	_attack += exp / 3;

	return _exp;
}
