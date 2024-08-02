#include "pch.h"


// 사양서 1
// 1. 1~3의 수를 입력받아서 Knight, Archer, Mage 세 직업중 하나를 선택해 생성(동적할당)하게 해주세요.
// 2. 컴퓨터도 난수를 받아서 1.과 같이 세팅해주세요.
// 3. 플레이어의 이름을 입력받고 Set 해주세요. 컴퓨터는 컴퓨터로.
// 4. 공격할 때 서로의 이름이 표시되게 해주세요. 예) Hanil이 컴퓨터를 공격했습니다.
// 5. Knight는 체력이 50프로 미만이 되면 공격력이 2배 강해집니다.
// 6. Mage는 마나를 5만큼 소비하여 공격을 합니다. 공격할 때 마나가 부족하다면 50만큼 회복하고 공격을 쉽니다.
// 7. Archer 30프로 확률로 크리티컬 데미지(3배 공격)을 합니다. 
// 8. 이 때 누가 이기는지 체크하고 이길 때 까지 반복


// 사양서 2
// 0. 컴퓨터와 전투할지 사냥으로 경험치를 얻을지 1, 2 입력으로 선택 (컴퓨터와 전투 패배시 혹은 고블린과 전투 후 0번으로 돌아옴)
// 1. Creature를 상속받는 Player를 만듭니다.
// 2. 사양서 1의 Knight와 Arhcher, Mage는 Player를 상속받습니다. 이 때 Player는 추상클래스입니다. 
// 3. Player의 속성에서 경험치가 추가됩니다.
// 4. Player가 고블린 10마리와 싸우는 전투에서 경험치를 얻고 경험치에 따라서 스탯이 올라갑니다. 
// 5. 전투가 끝나고 사양서 1의 게임을 다시해서 이기면 프로그램 종료




void Type(int PlayerType, Player** player)
{
	if (PlayerType == 1)
	{
		*player = new Knight(50, 50, 10, 100, 100);
	}

	else if (PlayerType == 2)
	{
		*player = new Archer(70, 50, 5, 100);
	}

	else if (PlayerType == 3)
	{
		*player = new Mage(30, 50, 15, 100);
	}
}

// 전투 모드
bool Mode1(Player* player, Player* computer)
{
	bool result = false;
	cout << "----------------------------------------------" << endl;
	while (true)
	{
		// player의 공격
		cout << endl;
		cout << player->Name() << "의 공격!!!" << endl;
		player->Attack(computer);
		computer->PrintCreature();

		if (computer->IsDead())
		{
			cout << "이겼습니다!" << endl;
			result = true;
			break;
		}

		cout << endl;
		cout << computer->Name() << "의 공격!!!" << endl;
		computer->Attack(player);
		player->PrintCreature();

		if (player->IsDead())
		{
			cout << "졌습니다!" << endl;
			break;
		}
	}

	return result;
}

// 사냥 모드
void Mode2(Player* player, Goblin*goblins[10])
{
	srand(time(NULL));
	int EXP = 0;

	for (int i = 0; i < 10; i++)
	{
		int time = rand();
		goblins[i] = new Goblin();
		goblins[i]->SetStat(time);
		EXP += goblins[i]->HP();
	}
	
	cout << "----------------------------------------------" << endl;
	while (true)
	{
		// player의 공격
		cout << endl;
		cout << player->Name() << "의 공격!!!" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (goblins[i]->IsDead())
			{
			}
			else
			{
				player->Attack(goblins[i]);
				goblins[i]->PrintCreature(i);
			}
		}
	
		if ((*goblins)->AllDead(goblins))
		{
			cout << endl;
			cout << "이겼습니다!" << endl;
			break;
		}
	
		// goblin의 공격
		cout << endl;
		cout << "Goblin의 공격!!!" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (goblins[i]->IsDead())
			{
			}
			else
			{
				goblins[i]->Attack(player);
			}
		}
	
		player->PrintCreature();
	
		if (player->IsDead())
		{
			cout << endl;
			cout << "졌습니다!" << endl;

			for (int i = 0; i < 10; i++)
			{
				EXP -= goblins[i]->HP();
			}

			break;
		}
	}

	player->getEXP(EXP);

	cout << endl;
	cout << "경험치 " << EXP << "상승!" << endl;
	cout << endl;
	player->PrintCreature();
	
	for (int i = 0; i < 10; i++) // -> 해제도 for문 돌면서 해야함
	{
		delete goblins[i];
	}
}



int main()
{
	// 이름 설정
	string PlayerName = "";
	string ComputerName = "Computer";
	cout << endl;
	cout << "이름을 입력해주세요." << endl;
	cout << endl;
	cin >> PlayerName;

	while (true)
	{
		bool result = false;

		// 게임모드 설정
		int GameMode = 0;
		cout << endl;
		cout << "----------------------------------------------" << endl;
		cout << endl;
		cout << "1~2의 숫자를 입력하여 게임 모드를 선택해주세요." << endl;
		cout << "1 : 전투" << endl;
		cout << "2 : 사냥" << endl;
		cout << endl;
		cin >> GameMode;

		if (GameMode != 1 && GameMode != 2)
		{
			cout << endl;
			cout << "다시 입력해주세요." << endl;
			cout << endl;
			cin >> GameMode;
		}
		else
		{
			// 직업 설정
			int PlayerType = 0;
			cout << endl;
			cout << "1~3의 숫자를 입력하여 직업을 선택해주세요." << endl;
			cout << "1 : Knight" << endl;
			cout << "2 : Archer" << endl;
			cout << "3 : Mage" << endl;
			cout << endl;

			cin >> PlayerType;

			while (true)
			{
				if (PlayerType != 1 && PlayerType != 2 && PlayerType != 3)
				{
					cout << endl;
					cout << "다시 입력해주세요." << endl;
					cout << endl;
					cin >> PlayerType;
				}
				else
				{
					Player* player;
					Type(PlayerType, &player);
					player->SetName(PlayerName);

					// 전투 시작
					if (GameMode == 1)
					{
						int ComputerType = 0;
						srand(time(NULL));
						ComputerType = rand() % 3 + 1;

						Player* computer;
						Type(ComputerType, &computer);
						computer->SetName(ComputerName);

						result = Mode1(player, computer);

						delete computer;
					}

					// 사냥 시작
					else if (GameMode == 2)
					{
						Goblin* goblins[10];
						Mode2(player, goblins);
					}

					delete player;

					break;
				}
			}

			if (result)
			{
				break;
			}
		}
	}

	return 0;
}

