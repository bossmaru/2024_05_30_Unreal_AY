#pragma once
class Creature
{
public:
	Creature(string name, int hp, int mp, int attack);
	virtual ~Creature(); // ���� virtual �� �� �Ⱥٿ��� ��


	// ����Լ� : ���
	virtual void PreAttack(Creature* other);
	virtual void Attack(Creature* other) abstract; // ���������Լ�
	virtual void TakeDamage(int amount);
	const string& GetName();
	const int& GetMaxHp();
	const int& GetCurHp();
	const int& GetCurMp();
	const int& GetCurAtk();
	bool IsDead();
	bool AllDead(vector<Creature*> group);

	// ���� ���� : ���� ������, ������Կ����� �Ѵ� �־����.
// ���������
//// World(const World& other);
// ������Կ�����
//// World& operator = (const World& other);


protected: // ������� : �Ӽ�
	string _name;
	int _curHp;
	int _maxHp;
	int _mp;
	int _attack;
};

