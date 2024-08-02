#pragma once
class Archer : public Player
{
public:
	Archer(string name, int hp, int mp, int attack);
	virtual ~Archer();

	// Player��(��) ���� ��ӵ�
	virtual void PreAttack(Creature* other) override;
	virtual void Attack(Creature* other) override;
	virtual void GetExp(int amount) override;
};

