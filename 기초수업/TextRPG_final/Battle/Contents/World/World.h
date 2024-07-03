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

	enum Start
	{
		YES = 1,
		NO = 2
	};

	World();
	~World();

	// ��� �ܿ� ���� Ŭ������ ����ϴ� "ȩ���" �����
	// ȩ����� �÷��̾� 10���� ���̵��ϴ� ����.
	// �� ���� 4���� �÷��̾ ����.
	// ��׷� �ý��� ���� : ���� �������� ���� �� ���� �� ���� �÷��̾ ����.
	// �̹� ���� �÷��̾�� �����ϸ� �ȵ�


	void Init(); // �ʱ�ȭ
	void Start();
	void End();

	bool Battle();
	void Hunt();

	void SelectClass(int num, string name, Creature** creature);
	void PlayMode();
	void SelectMonster(int monsterType);
	void ClonePlayers();
	void BossBattle();
	void BattleWin();

	struct PlayerPair
	{
		Creature* _player;
		int _id;
		int _damage;
	};

private:

	Creature* _player;
	Creature* _computer;
	Creature* _monster;
	
	// vector<shared_ptr<Creature>> _players;
	vector<Creature*> _monsters;
	vector<Creature*> _players;
	Creature* _boss;
	// vector<PlayerPair*> _players;
};

