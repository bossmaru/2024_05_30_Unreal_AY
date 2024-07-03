#include "pch.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int mp, int attack)
: Creature(name, hp, mp, attack)
{
}

Monster::~Monster()
{
}

void Monster::Attack(Creature* other)
{
	// PreAttack(other);
	if (IsDead() || other->IsDead())
	{
	}
	else
	{
		other->TakeDamage(_attack);
	}
}

void Monster::GroupAttack(Creature** arr, int size, Creature player)
{
}

void Monster::TakeDamage(int amount)
{
	_curHp -= amount;

	if (_curHp < 0)
	{
		_curHp = 0;
	}
}
