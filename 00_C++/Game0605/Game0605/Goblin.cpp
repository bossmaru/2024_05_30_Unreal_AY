#include "pch.h"
#include "Goblin.h"

Goblin::Goblin()
{
}

Goblin::Goblin(int hp, int mp, int attack)
: Creature(hp, mp, attack)
{
}

Goblin::~Goblin()
{
}

void Goblin::PrintCreature(int index)
{
	cout << "Goblin " << index + 1 << "ÀÇ HP : " << _hp << endl;
}

void Goblin::SetStat(int time)
{
	_hp = time % 21 + 30;
	_mp = 100;
	_attack = time % 4 + 2;
}

bool Goblin::AllDead(Goblin*arr[10])
{
	bool Dead = true;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i]->IsDead())
		{
		}
		else
		{
			Dead = false;
		}
	}

	return Dead;
}


