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
	cout << _name << "(Archer) 가 " << other->GetName() << "에게 공격을 시도합니다." << endl;
}

void Archer::Attack(Creature* other)
{
	if (other->IsDead())
	{
	}
	else
	{
		// this->
		// Creature::PreAttack(other); // 멤버함수를 호출하기 위한 조건 ... 객체가 항상 있어야 한다.
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
