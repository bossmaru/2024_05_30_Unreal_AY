#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int mp, int attack);
	virtual ~Player(); // virtual �ٿ������

protected:
	int _exp;
};

