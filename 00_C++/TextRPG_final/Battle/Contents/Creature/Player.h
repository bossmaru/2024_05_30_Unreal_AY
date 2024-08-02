#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int mp, int attack);
	virtual ~Player(); // virtual ºÙ¿©Áà¾ßÇÔ

	virtual void Attack(Creature* other);
	virtual void PrintInfo();
	virtual void GetExp(int amount);

protected:
	int _curExp;
	int _maxExp;
};

