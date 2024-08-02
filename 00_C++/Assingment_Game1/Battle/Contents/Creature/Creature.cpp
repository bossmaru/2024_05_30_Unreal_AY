#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int mp, int attack)
: _name(name), _curHp(hp), _attack(attack), _maxHp(hp), _mp(mp)
{
}

Creature::~Creature()
{
}

void Creature::PrintInfo()
{
	cout << endl;
	cout << "--------------" << endl;
	cout << "ÀÌ¸§ : " << _name << endl;
	cout << "HP : " << _curHp << endl;
	cout << "ATTACK : " << _attack << endl;
	cout << "--------------" << endl;
	cout << endl;
}

void Creature::PreAttack(Creature* other)
{
}

void Creature::TakeDamage(int amount)
{
	_curHp -= amount;
	
	if (_curHp < 0)
	{
		_curHp = 0;
	}

	PrintInfo();
}

const string& Creature::GetName()
{
	return _name;
}

const int& Creature::GetMaxHp()
{
	return _maxHp;
}

const int& Creature::GetCurHp()
{
	return _curHp;
}

bool Creature::IsDead()
{
	return _curHp <= 0;
}

bool Creature::AllDead(vector<Creature*> group)
{
	bool end = false;

	for (int i = 0; i < group.size(); i++)
	{
		if (group[i]->IsDead())
		{
			end = true;
		}
		else
		{
			end = false;
		}
	}

	return end;
}
