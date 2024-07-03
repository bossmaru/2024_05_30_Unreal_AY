#include "pch.h"
#include "World.h"
#include "string"

World::World()
: _player(nullptr)
, _computer(nullptr)
{
}

World::~World()
{
	if(_player != nullptr)
	{
		delete _player;
	}
	if (_computer != nullptr)
	{
		delete _computer;
	}
}

// World::World(const World& other)
// {
// 	_player = new Creature(*other._player);
// }
// 
// World& World::operator=(const World& other)
// {
// 	// TODO: ���⿡ return ���� �����մϴ�.
// }
// 

void World::Init()
{
	Start();
	PlayMode();
}

void World::Start()
{
	int playerNum = 0;
	string name;

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "�̸��� �Է����ּ���." << endl;
	cout << endl;
	cin >> name;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "1~3������ Ŭ������ �Է����ּ���." << endl;
	cout << "1 : Knight" << endl;
	cout << "2 : Archer" << endl;
	cout << "3 : Mage" << endl;
	cout << endl;
	cin >> playerNum;

	SelectClass(playerNum, name, &_player);
}

void World::SelectClass(int num, string name, Creature** creature)
{
	switch (num)
	{
	case PlayerType::KNIGHT:
	{
		*creature = new Knight(name, KnightStat::KNIGHT_HP, KnightStat::KNIGHT_MP, KnightStat::KNIGHT_ATTACK);
		
		break;
	}
	case PlayerType::ARCHER:
	{
		*creature = new Archer(name, ArcherStat::ARCHER_HP, ArcherStat::ARCHER_MP, ArcherStat::ARCHER_ATTACK);
		break;
	}
	case PlayerType::MAGE:
	{
		*creature = new Mage(name, MageStat::MAGE_HP, MageStat::MAGE_MP, MageStat::MAGE_ATTACK);
		break;
	}
	default:
	{
		cout << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
	}
	}
}

void World::PlayMode()
{
	bool end = false;
	int playMode = 0;

	while (true)
	{
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << "��Ʋ��带 �Է����ּ���." << endl;
		cout << "1 : ����" << endl;
		cout << "2 : ���" << endl;
		cout << endl;
		cin >> playMode;

		switch (playMode)
		{
		case PlayMode::BATTLE:
		{
			int comNum = rand() % 3 + 1;
			SelectClass(comNum, "Computer", &_computer);
			cout << endl;
			cout << "------------------------------------------------" << endl;
			cout << "������ �����մϴ�!" << endl;
			cout << endl;
			end = Battle();
			break;
		}
		case PlayMode::HUNT:
		{
			Hunt();
			cout << "------------------------------------------------" << endl;
			cout << "����� �Ϸ��Ͽ� ����ġ�� ȹ���Ͽ����ϴ�!" << endl;
			cout << endl;
			cout << "< ��� >" << endl;
			_player->PrintInfo();
			break;
		}
		default:
		{
			cout << endl;
			cout << "�߸��� �Է��Դϴ�" << endl;
			break;
		}
		}

		if (end == true)
		{
			End();
			break;
		}
	}
}

bool World::Battle()
{
	bool end = false;
	while (true)
	{
		_player->PreAttack(_computer);
		_player->Attack(_computer);
		if (_computer->IsDead())
		{
			end = true;
			break;
		}
		_computer->PreAttack(_player);
		_computer->Attack(_player);
		if (_player->IsDead())
		{
			cout << endl;
			cout << "�������� �й��Ͽ����ϴ�!" << endl;
			cout << endl;
			break;
		}
	}

	return end;
}

void World::Hunt()
{
	int monsterType = 0;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "����� ���͸� �������ּ���." << endl;
	cout << "1 : ���" << endl;
	cout << endl;
	cin >> monsterType;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "����� �����մϴ�!" << endl;
	cout << endl;
	SelectMonster(monsterType);
}

void World::SelectMonster(int monsterType)
{
	switch (monsterType)
	{
	case MonsterType::GOBLIN:
	{
		srand(time(nullptr));
		for (int i = 0; i < MonsterNum::GOBLIN; i++)
		{
			string name = "";
			int hp = rand() % 21 + 30;
			int mp = 100;
			int attack = rand() % 4 + 2;
			_monsters[i] = new Goblin(name, hp, mp, attack);
			// dynamic_cast<Goblin*>(goblins[i]); (����)
		}

		_player->GroupAttack(_monsters, MonsterNum::GOBLIN);

		for (int i = 0; i < MonsterNum::GOBLIN; i++)
		{
			delete goblins[i];
		}
	}
	}
}

void World::End()
{
	int restart = 0;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "�������� �¸��Ͽ����ϴ�!!!" << endl;
	cout << endl;
	cout << "������ �ٽ� �����Ͻðڽ��ϱ�? " << endl;
	cout << "1 : Y" << endl;
	cout << "2 : N" << endl;
	cout << endl;
	cin >> restart;

	switch (restart)
	{
	case Restart::YES:
	{
		Init();
		break;
	}
	case Restart::NO:
	{
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << "������ �����մϴ�." << endl;
		cout << endl;
		break;
	}
	default:
	{
		cout << endl;
		cout << "�߸��� �Է��Դϴ�" << endl;
		break;
	}
	}
}
