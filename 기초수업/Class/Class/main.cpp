#include "pch.h"

// 1. Player�� ��ӹ޴� 3���� Ŭ������ ���弼��.
// 2. main�� �� �� 2���� ��ü�� ����ð�
// 3. ��ü���� �ο��� �մϴ�.
// 4. �̸� �Ѹ��� ���� �� ���� �ݺ�

// 1. Player�� ��ӹ޴� Goblin ...(hp, mp, attack)
// 2. Main�� Creature 1��, Goblin 10�� �迭�� ������ּ���.
// 3. �� �� Goblin�� ü���� 30 ~ 50 ����, ���ݷ��� 2 ~ 5 ���� ������ ����
// 4. Player�� �װų� Goblin 10������ �� �״� ��쿡 ���� ��. �� �ܿ� �ݺ�.
// ... �� �� Goblin�� �׾��� �ϸ� Attack�� �������� �ʰ�.
// ���� ��� �ѹ��� �� ������, ����� 10���� �ѹ��� ���� ����


// 1. Player�� ��ӹ޴� 3���� Ŭ������ ���弼��.
// 2. main�� �� �� 2���� ��ü�� ����ð�(�����Ҵ�, �ڷ����� Creature*)
// 3. ��ü���� �ο��� �մϴ�.(Attack�� �����Լ��� ����)
// 4. �̸� �Ѹ��� ���� �� ���� �ݺ�

// -> ��ĳ����(�ڽ�->�θ�)�� ��ü��, �θ� Ȥ�� �ڽ� Ŭ�������� virtual Ű����� �Լ��� ������ ��
// vftable�� ���������, �̸� �����Ͽ� �ش� Ÿ�Կ� �´� �Լ��� ȣ���ϰ� �ȴ�.




// ��缭 1
// 1. 1~3�� ���� �Է¹޾Ƽ� Knight, Archer, Mage �� ������ �ϳ��� ������ ����(�����Ҵ�)�ϰ� ���ּ���.
// 2. ��ǻ�͵� ������ �޾Ƽ� 1.�� ���� �������ּ���.
// 3. �÷��̾��� �̸��� �Է¹ް� Set ���ּ���. ��ǻ�ʹ� ��ǻ�ͷ�.
// 4. ������ �� ������ �̸��� ǥ�õǰ� ���ּ���. ��) Hanil�� ��ǻ�͸� �����߽��ϴ�.
// 5. Knight�� ü���� 50���� �̸��� �Ǹ� ���ݷ��� 2�� �������ϴ�.
// 6. Mage�� ������ 5��ŭ �Һ��Ͽ� ������ �մϴ�. ������ �� ������ �����ϴٸ� 50��ŭ ȸ���ϰ� ������ ���ϴ�.
// 7. Archer 30���� Ȯ���� ũ��Ƽ�� ������(3�� ����)�� �մϴ�. 
// 8. �� �� ���� �̱���� üũ�ϰ� �̱� �� ���� �ݺ�


// ��缭 2
// 0. ��ǻ�Ϳ� �������� ������� ����ġ�� ������ 1, 2 �Է����� ���� (��ǻ�Ϳ� ���� �й�� Ȥ�� ����� ���� �� 0������ ���ƿ�)
// 1. Creature�� ��ӹ޴� Player�� ����ϴ�.
// 2. ��缭 1�� Knight�� Arhcher, Mage�� Player�� ��ӹ޽��ϴ�. �� �� Player�� �߻�Ŭ�����Դϴ�. 
// 3. Player�� �Ӽ����� ����ġ�� �߰��˴ϴ�.
// 4. Player�� ��� 10������ �ο�� �������� ����ġ�� ��� ����ġ�� ���� ������ �ö󰩴ϴ�. 
// 5. ������ ������ ��缭 1�� ������ �ٽ��ؼ� �̱�� ���α׷� ����



void PrintPlayers(Creature* p1, Creature* p2)
{
	p1->PrintCreature();
	p2->PrintCreature();
}

int main()
{
	//	Creature* player = new Creature(100, 100, 5);
	//	Goblin* goblin_G[10]; 
	//	
	//
	//	// 10�� �ѹ��� �����̷� �ְ� ������ �޾ƿö� ������ �ִµ� �� �Ⱦ�
	//	Goblin* goblins = new Goblin[10];
	//	delete[] goblins;
	//
	//
	//	srand(time(NULL));
	//
	//	for (int i = 0; i < 10; i++)
	//	{
	//		int time = rand();
	//		goblin_G[i] = new Goblin();
	//		goblin_G[i]->SetStat(time);
	//	}
	//
	//	while (true)
	//	{
	//		// ���� ����
	//		cout << endl;
	//		cout << "Creature�� ����!!!" << endl;
	//		for (int i = 0; i < 10; i++)
	//		{
	//			if (goblin_G[i]->IsDead())
	//			{
	//			}
	//			else
	//			{
	//				player->Attack(goblin_G[i]);
	//				goblin_G[i]->PrintPlayerGroup(*goblin_G[i], i);
	//			}
	//		}
	//
	//		if ((*goblin_G)->AllDead(*goblin_G, 10))
	//		{
	//			cout << endl;
	//			cout << "�̰���ϴ�!" << endl;
	//			break;
	//		}
	//
	//		// ����� ����
	//		cout << endl;
	//		cout << "Goblin�� ����!!!" << endl;
	//		for (int i = 0; i < 10; i++)
	//		{
	//			if (goblin_G[i]->IsDead())
	//			{
	//			}
	//			else
	//			{
	//				goblin_G[i]->Attack(player);
	//			}
	//		}
	//
	//		player->PrintCreature();
	//
	//		if (player->IsDead())
	//		{
	//			cout << endl;
	//			cout << "�����ϴ�!" << endl;
	//			break;
	//		}
	//	}
	//
	//
	//	for (int i = 0; i < 10; i++) // -> ������ for�� ���鼭 �ؾ���
	//	{
	//		delete goblin_G[i];
	//	}
	//
	//	delete player;
	//
	//
	//	return 0;
	//}
	//
	//	// 1. Player�� ��ӹ޴� 3���� Ŭ������ ���弼��.
	//	// 2. main�� �� �� 2���� ��ü�� ����ð�(�����Ҵ�, �ڷ����� Creature*)
	//	// 3. ��ü���� �ο��� �մϴ�.(Attack�� �����Լ��� ����)
	//	// 4. �̸� �Ѹ��� ���� �� ���� �ݺ�
	//
	//	// Creature* player = new Creature(50, 10, 5);
	//	// Creature* knight = new Knight(100, 5, 15, 100);
	//	// 
	//	// 
	//	// while (true)
	//	// {
	//	// 	player->Attack(knight);
	//	// 	PrintPlayers(player, knight);
	//	// 	cout << endl;
	//	// 
	//	// 	knight->Attack(player);
	//	// 	PrintPlayers(player, knight);
	//	// 	cout << endl;
	//	// 
	//	// 	if (player->IsDead())
	//	// 	{
	//	// 		cout << "�����ϴ�!!!" <<  endl;
	//	// 		break;
	//	// 	}
	//	// 
	//	// 	else if (knight->IsDead())
	//	// 	{
	//	// 		cout << "�̰���ϴ�!!!" << endl;
	//	// 		break;
	//	// 	}
	//	// }
	//	// 
	//	// delete knight; // virtual �Ⱦ��� Player�� ������
	//	// delete player;
	//	// 
	//	// 
	//	// 
	//	// return 0;
	//
	//
	//	// Creature p(50, 10, 5);
	//	// Knight k(100, 5, 15, 100);
	//	// 
	//	// while (true)
	//	// {
	//	// 	p.Attack(&k);
	//	// 	k.Attack(&p);
	//	// 	
	//	// 
	//	// 	if (p.IsDead() || k.IsDead())
	//	// 	{
	//	// 		break;
	//	// 	}
	//	// }
	//	// 
	//	// p.PrintCreature();
	//
	//	
	//	
	//	
	//	// Creature p(100, 100, 5);
	//	// Goblin g_arr[10];
	//	// 
	//	// srand(time(NULL));
	//	// for (int i = 0; i < 10; i++)
	//	// {
	//	// 	int time = rand();
	//	// 	g_arr[i].SetStat(time);
	//	// }
	//	// 
	//	// while (true)
	//	// {
	//	// 	// ���� ����
	//	// 	cout << endl;
	//	// 	cout << "Player�� ����!!!" << endl;
	//	// 	for (int i = 0; i < 10; i++)
	//	// 	{
	//	// 		if (g_arr[i].IsDead())
	//	// 		{
	//	// 		}
	//	// 		else
	//	// 		{
	//	// 			p.Attack(&g_arr[i]);
	//	// 			g_arr[i].PrintGoblin(g_arr[i], i);
	//	// 		}
	//	// 	}
	//	// 
	//	// 	if (g_arr->AllDead(g_arr, 10))
	//	// 	{
	//	// 		cout << endl;
	//	// 		cout << "�̰���ϴ�!" << endl;
	//	// 		break;
	//	// 	}
	//	// 
	//	// 	// ����� ����
	//	// 	cout << endl;
	//	// 	cout << "Goblin�� ����!!!" << endl;
	//	// 	for (int i = 0; i < 10; i++)
	//	// 	{
	//	// 		if (g_arr[i].IsDead())
	//	// 		{
	//	// 		}
	//	// 		else
	//	// 		{
	//	// 			g_arr[i].Attack(&p);
	//	// 		}
	//	// 	}
	//	// 
	//	// 	p.PrintCreature();
	//	// 
	//	// 	if (p.IsDead())
	//	// 	{
	//	// 		cout << endl;
	//	// 		cout << "�����ϴ�!" << endl;
	//	// 		break;
	//	// 	}
	//	// 
	//	// }
	//	// 


	string name;
	cin >> name;

	Creature* knight = new Knight(500, 2, 15, 0);
	knight->SetName(name);

	knight->PrintCreature();

	delete knight;

	return 0;

}

