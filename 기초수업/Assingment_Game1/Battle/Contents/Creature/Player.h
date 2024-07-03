#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int mp, int attack);
	virtual ~Player(); // virtual ºÙ¿©Áà¾ßÇÔ

	virtual void GroupAttack(vector<Creature*> group, string GroupName);
	virtual void GetExp(int amount);

protected:
	int _exp;
};

