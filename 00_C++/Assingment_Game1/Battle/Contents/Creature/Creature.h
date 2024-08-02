#pragma once
class Creature
{
public:
	Creature(string name, int hp, int mp, int attack);
	virtual ~Creature(); // 여기 virtual 은 꼭 안붙여도 됨

	// 멤버함수 : 기능
	void PrintInfo();
	virtual void PreAttack(Creature* other);
	// virtual void GroupAttack(Creature** arr, string GroupName, int size);
	virtual void Attack(Creature* other) abstract; // 순수가상함수
	virtual void TakeDamage(int amount);
	// virtual void GetExp(int amount);
	const string& GetName();
	const int& GetMaxHp();
	const int& GetCurHp();
	bool IsDead();
	bool AllDead(vector<Creature*> group);

protected: // 멤버변수 : 속성
	string _name;
	int _curHp;
	int _maxHp;
	int _mp;
	int _attack;
};

