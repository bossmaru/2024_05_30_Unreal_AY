#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int mp, int attack);
	virtual ~Monster(); // virtual �ٿ������

	virtual void Attack(Creature* other);
};

