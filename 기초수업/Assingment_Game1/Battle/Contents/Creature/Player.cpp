#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int mp, int attack)
: Creature(name, hp, mp, attack)
, _exp(0)
{
}

Player::~Player()
{
}

void Player::GroupAttack(vector<Creature*> group, string GroupName)
{
	int exp = 0;
	while (true)
	{
		cout << endl;
		cout << "--------------" << endl;
		cout << GetName() << "�� ����!!!" << endl;
		cout << endl;

		for (int i = 0; i < group.size(); i++)
		{
			exp += group[i]->GetCurHp();
		}

		for (int i = 0; i < group.size(); i++)
		{
			// ���� ����
			Attack(group[i]);
			cout << i + 1 << "�� " << GroupName << "�� HP : " << group[i]->GetCurHp() << endl;
		}
		// ���� ������ ��
		if (AllDead(group))
		{
			cout << endl;
			cout << "�̰���ϴ�!" << endl;
			cout << endl;
			break;
		}

		cout << endl;
		cout << "--------------" << endl;
		cout << GroupName << "�� ����!!!" << endl;
		cout << endl;
		for (int i = 0; i < group.size(); i++)
		{
			// ������ ����
			group[i]->Attack(this);
		}
		cout << GetName() << "�� HP : " << GetCurHp() << endl;

		// ���� ������ ��
		if (IsDead())
		{
			cout << endl;
			cout << "�����ϴ�!" << endl;
			cout << endl;
			break;
		}
		for (int i = 0; i < group.size(); i++)
		{
			exp -= group[i]->GetCurHp();
		}
	}
	GetExp(exp);
}

void Player::GetExp(int amount)
{
}
