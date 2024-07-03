#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int mp,int attack)
: Player(name, hp, mp, attack)
{
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* other)
{
	if (IsDead())
	{
	}
	else
	{
		PreAttack(other);
		if (_mp < 5)
		{
			_mp = 50;
		}
		else
		{
			_mp -= 5;
			other->TakeDamage(_attack);
		}
	}
}
