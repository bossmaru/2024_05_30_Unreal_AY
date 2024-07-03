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
	if (other->IsDead())
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
	_curExp += amount;
	if (_curExp >= _maxExp)
	{
		_curExp -= _maxExp;
		_curHp += _maxExp * 3;
		_attack += _maxExp / 3;
		_mp += _maxExp / 3;
	}
}
