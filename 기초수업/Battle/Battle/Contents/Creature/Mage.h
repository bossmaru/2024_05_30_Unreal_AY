#pragma once
class Mage : public Player
{
public:
	Mage(string name, int hp, int mp, int attack);
	virtual ~Mage();

	// Player��(��) ���� ��ӵ�
	virtual void Attack(Creature* other) override;

};
