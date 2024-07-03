#include "pch.h"
#include "Knight.h"

Knight::Knight()
{
	_type = "Knight";
	_stamina = 0;
}

Knight::Knight(int hp, int mp, int attack, int exp, int stamina)
: Player(hp, mp, attack, exp)
{
	_type = "Knight";
	_stamina = stamina;
}

Knight::~Knight()
{
}

void Knight::TakeDamage(int amount)
{
	_hp -= amount;

	if (_hp <= 0)
	{
		_hp = 0;
	}

	if (_hp < 25)
	{
		_attack *= 2;
	}
}

void Knight::PrintCreature()
{
	cout << "** " << _name << "(" << _type << ")" << " **" << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "ATTACK : " << _attack << endl;
	cout << "STAMINA : " << _stamina << endl;
}

int Knight::getEXP(int exp)
{
	_exp += exp;
	_hp += exp / 4;
	_mp += exp / 4;
	_attack += exp / 4;
	_stamina += exp / 4;

	return _exp;
}

