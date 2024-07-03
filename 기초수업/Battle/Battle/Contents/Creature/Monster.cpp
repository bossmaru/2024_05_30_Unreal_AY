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
	PreAttack(other);
	other->TakeDamage(_attack);
}
