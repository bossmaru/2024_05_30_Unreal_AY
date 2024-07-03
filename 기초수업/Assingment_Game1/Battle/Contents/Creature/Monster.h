#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int mp, int attack);
	virtual ~Monster(); // virtual ºÙ¿©Áà¾ßÇÔ

	virtual void Attack(Creature* other);
	virtual void GroupAttack(Creature** arr, int size, Creature player);
	virtual void TakeDamage(int amount);

protected:
};
