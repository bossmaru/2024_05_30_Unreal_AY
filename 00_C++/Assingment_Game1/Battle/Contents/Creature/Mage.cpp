#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int mp,int attack)
: Player(name, hp, mp, attack)
{
}

Mage::~Mage()
{
}

void Mage::PreAttack(Creature* other)
{
	cout << _name << "(Mage) �� " << other->GetName() << "���� ������ �õ��մϴ�." << endl;
}

void Mage::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
	}
	else
	{
		// PreAttack(other);
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

void Mage::GetExp(int amount)
{
	_exp += amount;
	_curHp += amount / 3;
	_mp += amount / 3;
	// _attack += amount / 3;
}
