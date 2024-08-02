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
// 	// TODO: 여기에 return 문을 삽입합니다.
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
	cout << "이름을 입력해주세요." << endl;
	cout << endl;
	cin >> name;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "1~3까지의 클래스를 입력해주세요." << endl;
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
		cout << "잘못된 입력입니다." << endl;
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
		cout << "배틀모드를 입력해주세요." << endl;
		cout << "1 : 전투" << endl;
		cout << "2 : 사냥" << endl;
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
			cout << "전투를 시작합니다!" << endl;
			cout << endl;
			end = Battle();
			break;
		}
		case PlayMode::HUNT:
		{
			Hunt();
			cout << "------------------------------------------------" << endl;
			cout << "사냥을 완료하여 경험치를 획득하였습니다!" << endl;
			cout << endl;
			cout << "< 결과 >" << endl;
			_player->PrintInfo();
			break;
		}
		default:
		{
			cout << endl;
			cout << "잘못된 입력입니다" << endl;
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
			cout << "전투에서 패배하였습니다!" << endl;
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
	cout << "사냥할 몬스터를 선택해주세요." << endl;
	cout << "1 : 고블린" << endl;
	cout << endl;
	cin >> monsterType;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "사냥을 시작합니다!" << endl;
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
			// dynamic_cast<Goblin*>(goblins[i]); (질문)
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
	cout << "전투에서 승리하였습니다!!!" << endl;
	cout << endl;
	cout << "게임을 다시 시작하시겠습니까? " << endl;
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
		cout << "게임을 종료합니다." << endl;
		cout << endl;
		break;
	}
	default:
	{
		cout << endl;
		cout << "잘못된 입력입니다" << endl;
		break;
	}
	}
}
