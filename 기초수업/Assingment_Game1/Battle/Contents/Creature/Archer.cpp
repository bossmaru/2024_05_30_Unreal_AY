#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int mp, int attack)
: Player(name, hp, mp, attack)
{
}

Archer::~Archer()
{
}

void Archer::PreAttack(Creature* other)
{
	cout << _name << "(Archer) �� " << other->GetName() << "���� ������ �õ��մϴ�." << endl;
}

void Archer::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
	}
	else
	{
		// this->
		// Creature::PreAttack(other); // ����Լ��� ȣ���ϱ� ���� ���� ... ��ü�� �׻� �־�� �Ѵ�.
		srand(time(NULL));
		float ratio = (rand() % 100) / (float)100;
		if (ratio < 0.3f)
		{
			other->TakeDamage(_attack * 3);
		}
		else
		{
			other->TakeDamage(_attack);
		}
	}
}

void Archer::GetExp(int amount)
{
	_exp += amount;
	_curHp += amount / 3;
	_mp += amount / 3;
	// _attack += amount / 3;
}
