#pragma once
class Creature
{
public:
	Creature(string name, int hp, int mp, int attack);
	virtual ~Creature(); // ���� virtual �� �� �Ⱥٿ��� ��

	// ����Լ� : ���
	void PrintInfo();
	virtual void PreAttack(Creature* other);
	// virtual void GroupAttack(Creature** arr, string GroupName, int size);
	virtual void Attack(Creature* other) abstract; // ���������Լ�
	virtual void TakeDamage(int amount);
	// virtual void GetExp(int amount);
	const string& GetName();
	const int& GetMaxHp();
	const int& GetCurHp();
	bool IsDead();
	bool AllDead(vector<Creature*> group);

protected: // ������� : �Ӽ�
	string _name;
	int _curHp;
	int _maxHp;
	int _mp;
	int _attack;
};

