#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int mp, int attack);
	virtual ~Knight(); // �ٿ������

	// Player��(��) ���� ��ӵ�
	virtual void Attack(Creature* other) override;

private:
	int _stamina;
};

