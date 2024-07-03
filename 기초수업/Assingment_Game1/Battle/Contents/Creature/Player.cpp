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
		cout << GetName() << "의 공격!!!" << endl;
		cout << endl;

		for (int i = 0; i < group.size(); i++)
		{
			exp += group[i]->GetCurHp();
		}

		for (int i = 0; i < group.size(); i++)
		{
			// 내가 공격
			Attack(group[i]);
			cout << i + 1 << "번 " << GroupName << "의 HP : " << group[i]->GetCurHp() << endl;
		}
		// 상대방 죽으면 끝
		if (AllDead(group))
		{
			cout << endl;
			cout << "이겼습니다!" << endl;
			cout << endl;
			break;
		}

		cout << endl;
		cout << "--------------" << endl;
		cout << GroupName << "의 공격!!!" << endl;
		cout << endl;
		for (int i = 0; i < group.size(); i++)
		{
			// 상대방이 공격
			group[i]->Attack(this);
		}
		cout << GetName() << "의 HP : " << GetCurHp() << endl;

		// 내가 죽으면 끝
		if (IsDead())
		{
			cout << endl;
			cout << "졌습니다!" << endl;
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
