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

void Knight::PreAttack(Creature* other)
{
	cout << _name << "(Knight) �� " << other->GetName() << "���� ������ �õ��մϴ�." << endl;
}

void Knight::Attack(Creature* other)
{
	if (IsDead() || other->IsDead())
	{
	}
	else
	{
		// PreAttack(other);
		float ratio = (float)_curHp / (float)_maxHp;

		if (ratio < 0.5f)
		{
			// ���� ü���� 50���� �̸�
			other->TakeDamage(_attack * 2);
		}
		else
		{
			other->TakeDamage(_attack);
		}
	}
}

void Knight::GetExp(int amount)
{
	_exp += amount;
	_curHp += amount / 4;
	_mp += amount / 4;
	// _attack += amount / 4;
	_stamina += amount / 4;
}
