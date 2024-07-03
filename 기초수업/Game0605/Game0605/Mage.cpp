#include "pch.h"
#include "Mage.h"

Mage::Mage()
{
	_type = "Mage";
}

Mage::Mage(int hp, int mp, int attack, int exp)
: Player(hp, mp, attack, exp)
{
	_type = "Mage";
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* c)
{
	// 6. Mage는 마나를 5만큼 소비하여 공격을 합니다. 공격할 때 마나가 부족하다면 50만큼 회복하고 공격을 쉽니다.
	if (_mp < 5)
	{
		_mp == 50;
	}
	else
	{
		_mp -= 5;
		c->TakeDamage(_attack);
	}
}

int Mage::getEXP(int exp)
{
	_exp += exp;
	_hp += exp / 3;
	_mp += exp / 3;
	_attack += exp / 3;

	return _exp;
}
