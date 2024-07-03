#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int mp, int attack);
	virtual ~Knight(); // �ٿ������

	// Player��(��) ���� ��ӵ�
	virtual void PreAttack(Creature* other) override;
	virtual void Attack(Creature* other) override;
	virtual void GetExp(int amount) override;

private:
	int _stamina;
};

