#include "pch.h"
#include "World.h"
#include "string"

World::World()
: _player(nullptr)
, _computer(nullptr)
, _monster(nullptr)
, _boss(nullptr)

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
	if (_monster != nullptr)
	{
		delete _monster;
	}
	if (_boss != nullptr)
	{
		delete _boss;
	}
	_monsters.clear();
	_players.clear();
}

// Ȩ ȭ��... �ʱ�ȭ, �÷��� ����
void World::Init()
{
	_player = nullptr;
	_computer = nullptr;
	_monsters = {};

	Start();
	PlayMode();
}

// �̸�, Ŭ���� �Է�
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
		if (name == "Computer")
		{
			*creature = new Knight(name, KNIGHT_HP * 1.5, KNIGHT_MP * 1.5, KNIGHT_ATTACK * 2);
		}
		else
		{
			*creature = new Knight(name, KNIGHT_HP, KNIGHT_MP, KNIGHT_ATTACK);
		}
		
		break;
	}
	case PlayerType::ARCHER:
	{
		if (name == "Computer")
		{
			*creature = new Archer(name, ARCHER_HP * 1.5, ARCHER_MP * 1.5, ARCHER_ATTACK * 2);
		}
		else
		{
			*creature = new Archer(name, ARCHER_HP, ARCHER_MP, ARCHER_ATTACK);
		}
		break;
	}
	case PlayerType::MAGE:
	{
		if (name == "Computer")
		{
			*creature = new Mage(name, MAGE_HP * 1.5, MAGE_MP * 1.5, MAGE_ATTACK * 2);
		}
		else
		{
			*creature = new Mage(name, MAGE_HP, MAGE_MP, MAGE_ATTACK);
		}
		break;
	}
	default:
	{
		cout << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
	}
}

void World::PlayMode()
{
	bool battleWin = false;
	int playMode = 0;

	// ���� �̱� �� ���� �ݺ�
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
			battleWin = Battle();
			break;
		}
		case PlayMode::HUNT:
		{
			_monsters = {};
			Hunt();
			cout << "------------------------------------------------" << endl;
			cout << "����� �Ϸ��Ͽ� ����ġ�� ȹ���Ͽ����ϴ�!" << endl;
			cout << endl;
			cout << "< ��� >" << endl;
			dynamic_cast<Player*>(_player)->PrintInfo();
			break;
		}
		default:
		{
			cout << endl;
			cout << "�߸��� �Է��Դϴ�" << endl;
			break;
		}
		}

		if (battleWin == true)
		{
			BattleWin();
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
		dynamic_cast<Player*>(_computer)->PrintInfo();
		if (_computer->IsDead())
		{
			end = true;
			break;
		}

		_computer->PreAttack(_player);
		_computer->Attack(_player);
		dynamic_cast<Player*>(_player)->PrintInfo();
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
		dynamic_cast<Goblin*>(_monster)->Clone(_monsters);
		dynamic_cast<Monster*>(_monster)->MonstersAttack(dynamic_cast<Player*>(_player), _monsters);

		for (int i = 0; i < MonsterNum::GOBLIN; i++)
		{
			delete _monsters[i];
		}
	}
	}
}

void World::ClonePlayers()
{
	for (int i = 0; i < 10; i++)
	{
		int classNum = rand() % 3 + 1;
		int random = rand() % 30 + 1;
		string playerName = _player->GetName() + " " + to_string(i + 1);

		switch(classNum)
		{
			case PlayerType::KNIGHT:
		{
			_players.push_back(new Knight(playerName, _player->GetCurHp() + random, _player->GetCurMp() + random, _player->GetCurAtk() + random));
			break;
		}
		case PlayerType::ARCHER:
		{
			_players.push_back(new Archer(playerName, _player->GetCurHp() + random, _player->GetCurMp() + random, _player->GetCurAtk() + random));
			break;
		}
		case PlayerType::MAGE:
		{
			_players.push_back(new Mage(playerName, _player->GetCurHp() + random, _player->GetCurMp() + random, _player->GetCurAtk() + random));
			break;
		}
		}
	}
}

void World::BossBattle()
{
	ClonePlayers();
	_boss = new HobGoblin("Boss", HG_HP, HG_MP, HG_ATTACK / _players.size());
	dynamic_cast<HobGoblin*>(_boss)->AggroAttack(_players);

	for (int i = 0; i < _players.size(); i++)
	{
		delete _players[i];
	}
}

void World::BattleWin()
{
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "�������� �¸��Ͽ����ϴ�!!!" << endl;
	cout << endl;
	cout << "�������� �����մϴ�." << endl;
	cout << "1 : Y" << endl;
	cout << "2 : N" << endl;
	cout << endl;
	int start = 0;
	cin >> start;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	switch (start)
	{
		case(YES):
		{
			cout << endl;
			cout << "���� ���� ����!!!" << endl;
			cout << endl;
			BossBattle();
			End();
		}
		case(NO):
		{
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

void World::End()
{
	int restart = 0;
	cout << endl;
	cout << "������ �ٽ� �����Ͻðڽ��ϱ�? " << endl;
	cout << "1 : Y" << endl;
	cout << "2 : N" << endl;
	cout << endl;
	cin >> restart;

	switch (restart)
	{
	case YES:
	{
		Init();
		break;
	}
	case NO:
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
