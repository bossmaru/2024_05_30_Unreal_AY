#include "pch.h"
#include "Creature.h"

Creature::Creature()
: _name("")
{
	_type = "";
	_hp = 0;
	_mp = 0;
	_attack = 0;
}

Creature::Creature(int hp, int mp, int attack)
: _name("")
{
	_hp = hp;
	_mp = mp;
	_attack = attack;
}

Creature::~Creature()
{
}

void Creature::PrintCreature()
{
	cout << "** " << _name << "(" << _type << ")" << " **" << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "ATTACK : " << _attack << endl;
}

void Creature::Attack(Creature* c)
{
	c->TakeDamage(_attack);
}

void Creature::TakeDamage(int amount)
{
	_hp -= amount;
	if (_hp <= 0)
	{
		_hp = 0;
	}
}

const int& Creature::HP()
{
	return _hp;
}

const string& Creature::Name()
{
	return _name;
}

const string& Creature::Type()
{
	return _type;
}

bool Creature::IsDead()
{
	return _hp <= 0;
}

void Creature::SetName(const string& name)
{
	_name = name;
}

void Creature::SetAttack()
{
	_attack *= 2;
}

