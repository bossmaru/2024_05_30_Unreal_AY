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

	// ���� ���� : ���� ������, ������Կ����� �Ѵ� �־����.
	// ���������
	//// World(const World& other);
	// ������Կ�����
	//// World& operator = (const World& other);

	void Init(); // �ʱ�ȭ

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

