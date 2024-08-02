#include "pch.h"
#include "World.h"

World::World()
: _player(nullptr)
, _computer(nullptr)
{
	Input();
	Init();
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
}

bool World::End()
{
	if (_player->IsDead() || _computer->IsDead())
	{
		return true;
	}
	return false;
}

void World::SelectBattle(int num)
{
	switch (num)
	{
	case NONE:
	{
		cout << "다시 입력해주세요." << endl;
		break;
	}
	case 
	default:
	{
		cout << "다시 입력해주세요." << endl;
		break;
	}
	}
}

void World::SelectPlayer(int num, string name, Creature** creature)
{
	switch (num)
	{
	case NONE:
	{
		cout << "다시 입력해주세요." << endl;
		break;
	}
	case KNIGHT:
	{
		*creature = new Knight(name, 500, 100, 15);
		break;
	}
	case ARCHER:
	{
		*creature = new Archer(name, 300, 100, 35);
		break;
	}
	case MAGE:
	{
		*creature = new Archer(name, 200, 100, 50);
		break;
	}
	default:
	{
		cout << "다시 입력해주세요." << endl;
		break;
	}
	}
}

	void World::Input()
{
	int playerNum = 0;
	int comNum = 0;
	string name;
	int battleMode = 0;

	cout << "이름을 입력해주세요." << endl;
	cout << endl;
	cin >> name;

	cout << "배틀모드를 입력해주세요." << endl;
	cout << "1 : 전투" << endl;
	cout << "2 : 사냥" << endl;
	cin >> battleMode;

	cout << "1~3까지의 클래스를 입력해주세요." << endl;
	cout << "1 : Knight" << endl;
	cout << "2 : Archer" << endl;
	cout << "3 : Mage" << endl;
	cout << endl;
	cin >> playerNum;
	comNum = rand() % 3 + 1;

	SelectPlayer(playerNum, name, &_player);
	SelectPlayer(comNum, "Computer", &_computer);
}


void World::Battle1()
{
	_player->Attack(_computer);
	_computer->Attack(_player);
}

void World::Battle2()
{

}
