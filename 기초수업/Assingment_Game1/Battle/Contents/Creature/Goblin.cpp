#include "pch.h"
#include "Goblin.h"
#include "string"

Goblin::Goblin(string name, int hp, int mp, int attack)
: Monster(name, hp, mp, attack)
{
}

Goblin::~Goblin()
{
}

void Goblin::Attack(Player* other)
{
}
