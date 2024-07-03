#pragma once
class World
{
public:
	enum PlayerType
	{
		KNIGHT = 1,
		ARCHER = 2,
		MAGE = 3
	};

	enum PlayMode
	{
		BATTLE = 1,
		HUNT = 2,
	};

	enum MonsterType
	{
		GOBLIN = 1,
	};

	enum Restart
	{
		YES = 1,
		NO = 2
	};

	World();
	~World();

	// 깊은 복사 : 복사 생성자, 복사대입연산자 둘다 있어야함.
	// 복사생성자
	//// World(const World& other);
	// 복사대입연산자
	//// World& operator = (const World& other);

	void Init(); // 초기화
	void End();

	bool Battle();
	void Hunt();



private:
	void SelectClass(int num, string name, Creature** creature);
	void PlayMode();
	void SelectMonster(int monsterType);

	Creature* _player;
	Creature* _computer;
	vector<Creature*>_monsters;

	void Start(); // 초기화
};

