#pragma once

#include "Creature.h"

class Goblin : public Creature
{
public:
	Goblin();
	Goblin(int hp, int mp, int attack);
	~Goblin();

	void PrintCreature(int index);
	void SetStat(int time);
	bool AllDead(Goblin*arr[10]);
};

