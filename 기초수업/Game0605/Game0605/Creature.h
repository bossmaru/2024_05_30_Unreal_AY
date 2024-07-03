#pragma once
class Creature
{
public:
	Creature();
	Creature(int hp, int mp, int attack);
	~Creature();

	virtual void PrintCreature();
	virtual void Attack(Creature* c);
	virtual void TakeDamage(int amount);
	const int& HP();
	const string& Name();
	const string& Type();
	bool IsDead();
	void SetName(const string&name);
	void SetAttack();

protected:
	string _type;
	int _hp;
	int _mp;
	int _attack;
	string _name;
};

