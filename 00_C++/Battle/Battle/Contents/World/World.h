#pragma once
class World
{
public:
	enum PlayerType
	{
		NONE = 0,
		KNIGHT = 1,
		ARCHER = 2,
		MAGE = 3
	};

	enum BattleMode
	{
		NONE = 0,
		BATTLE1 = 1,
		BATTLE2 = 2,
	};

	World();
	~World();

	// 깊은 복사 : 복사 생성자, 복사대입연산자 둘다 있어야함.
	// 복사생성자
	//// World(const World& other);
	// 복사대입연산자
	//// World& operator = (const World& other);

	void Init(); // 초기화

	bool End();

	void Battle1();
	void Battle2();

private:

	void SelectBattle(int num);
	void SelectPlayer(int num, string name, Creature** creature);

	Creature* _player;
	Creature* _computer;

	void Input();
};

