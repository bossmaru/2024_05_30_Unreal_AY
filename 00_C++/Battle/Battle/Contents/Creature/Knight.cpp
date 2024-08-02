#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int mp, int attack)
: Player(name, hp, mp, attack)
, _stamina(0)
{
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	if (IsDead())
	{
	}
	else
	{
		PreAttack(other);
		float ratio = (float)_curHp / (float)_maxHp;

		if (ratio < 0.5f)
		{
			// 현재 체력이 50프로 미만
			other->TakeDamage(_attack * 2);
		}
		else
		{
			other->TakeDamage(_attack);
		}
	}
}
