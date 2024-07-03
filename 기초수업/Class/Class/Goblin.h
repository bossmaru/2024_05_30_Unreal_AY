#pragma once

#include "Creature.h"

class Goblin : public Creature
{
public:
	Goblin();
	Goblin(int hp, int mp, int attack);
	virtual ~Goblin(); // �ڽ� ���еǰ� override �ᵵ �ǵ� �Ƚᵵ ��

	void SetStat(int time);

	void SetHP(int hp) { _hp = hp; }

	bool AllDead(Goblin arr[], int size);
	
	// void PrintPlayerGroup(Creature p, int index);

	virtual void Attack(Creature* p) override;

	
};

