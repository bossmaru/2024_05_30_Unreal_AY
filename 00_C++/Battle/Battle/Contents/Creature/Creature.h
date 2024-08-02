#pragma once
class Creature
{
public:
	Creature(string name, int hp, int mp, int attack);
	virtual ~Creature(); // 여기 virtual 은 꼭 안붙여도 됨

	// 멤버함수 : 기능
	void PrintInfo();
	void PreAttack(Creature* other);
	virtual void Attack(Creature* other) abstract; // 순수가상함수
	void TakeDamage(int amount);

	bool IsDead()
	{
		return _curHp <= 0;
	}

protected: // 멤버변수 : 속성
	string _name;
	int _curHp;
	int _maxHp;
	int _mp;
	int _attack;
};

