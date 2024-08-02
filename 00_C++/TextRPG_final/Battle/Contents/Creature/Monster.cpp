#include "pch.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int mp, int attack)
: Creature(name, hp, mp, attack)
{
}

Monster::~Monster()
{
}

void Monster::Attack(Creature* other)
{
	// PreAttack(other);
	if (IsDead() || other->IsDead())
	{
	}
	else
	{
		other->TakeDamage(_attack);
	}
}

void Monster::TakeDamage(int amount)
{
	_curHp -= amount;

	if (_curHp < 0)
	{
		_curHp = 0;
	}
}

void Monster::MonstersAttack(Player* player, vector<Creature*> group)
{
	while (true)
	{
		cout << endl;
		cout << "--------------" << endl;
		cout << player->GetName() << "�� ����!!!" << endl;
		cout << endl;

		for (int i = 0; i < group.size(); i++)
		{
			// ���� ����
			int exp = group[i]->GetCurHp();
			player->Attack(group[i]);
			if (group[i]->IsDead())
			{
				exp -= group[i]->GetCurHp();
				player->GetExp(exp);
			}
			cout << group[i]->GetName() << "�� HP : " << group[i]->GetCurHp() << endl;
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
		cout << "������ ����!!!" << endl;
		cout << endl;
		for (int i = 0; i < group.size(); i++)
		{
			// ������ ����
			group[i]->Attack(player);
		}
		cout << player->GetName() << "�� HP : " << player->GetCurHp() << endl;

		// ���� ������ ��
		if (player->IsDead())
		{
			cout << endl;
			cout << "�����ϴ�!" << endl;
			cout << endl;
			break;
		}
	}
}
