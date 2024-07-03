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

	// ���� ���� : ���� ������, ������Կ����� �Ѵ� �־����.
	// ���������
	//// World(const World& other);
	// ������Կ�����
	//// World& operator = (const World& other);

	void Init(); // �ʱ�ȭ
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

	void Start(); // �ʱ�ȭ
};

