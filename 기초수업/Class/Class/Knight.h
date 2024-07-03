#pragma once

#include "Creature.h"


class Creature; // ���漱��

class Knight : public Creature
{
public:
	Knight();
	Knight(int hp, int mp, int attack, int stamina);
	virtual ~Knight();

	// �Լ� �������̵� : �θ��� �Լ��� ������
	virtual void Attack (Creature* p) override;
	virtual void PrintCreature() override;


private:
	int _stamina;
};

