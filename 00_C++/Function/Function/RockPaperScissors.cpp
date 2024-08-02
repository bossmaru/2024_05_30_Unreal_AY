#include <iostream>

using namespace std;

// 솔루션 : 서점
// 프로젝트 : 구역
// 파일 : 책



enum RSP
{
	SCISSORS = 1,
	ROCK = 2,
	PAPER = 3
};


int main()
{
	
	srand(time(NULL));
	// 과제 2
	// 가위바위보 게임 만들기
	// 1 -> 가위, 2 -> 바위, 3 -> 보
	// 숫자를 1~3 입력받는다. (단, 다른 수를 입력하면 다시)
	// 컴퓨터가 1~3까지 숫자를 랜덤하게 갖고 있습니다.
	// 누가 어떤 거 냈는지 출력
	// 이 모든 과정을 내가 이길 때 까지 반복

	// (선택과제)... 자유롭게 함수화



	// 과제 3
	// 스무고개 게임 만들기
	// 1. 컴퓨터가 1~500까지의 랜덤한 수를 갖고 있는다.
	// 2. 플레이어가 1~500까지의 수를 입력 받는다. 단 다른 수를 입력하면 다시
	// 3. 플레이어가 입력한 수가 컴퓨터의 수와 비교했을 때 대소를 출력
	// 예시) 컴퓨터 250, 플레이어 100 -> 플레이어의 수가 더 작습니다.
	// 4. 이를 9번 반복, 맞추면 끝
	// 5. 맞추는 결과를 출력해오세요.

	// (선택과제)...자유롭게 함수화


	// 과제 4
	// 포인터와 참조에 대해서 조사해보시오.

	int playerNum = 0;
	int cumNum = 0;

	// 숫자 1~3을 입력받는다.
	cout << "1~3까지의 숫자를 입력해주세요." << endl;

	//  컴퓨터가 1~3까지 랜덤한 수
	cumNum = (rand() % 3 + 1);


	// 잘못 입력한 경우
	while (true)
	{
		cin >> playerNum;
		if (playerNum < 1 or playerNum > 3)
		{
			cout << "다시 입력해주세요" << endl;
		}

		// 제대로 입력한 경우
		else
		{
			if (playerNum == SCISSORS)
			{
				cout << "나 : 가위" << endl;
				if (cumNum == ROCK)
				{
					cout << "컴퓨터 : 바위" << endl;
					cout << "졌습니다!" << endl;
				}
				else if (cumNum == PAPER)
				{
					cout << "컴퓨터 : 보" << endl;
					cout << "이겼습니다!" << endl;
					break;
				}
				else
				{
					cout << "컴퓨터 : 가위" << endl;
					cout << "비겼습니다!" << endl;
				}
			}

			else if (playerNum == ROCK)
			{
				cout << "나 : 바위" << endl;
				if (cumNum == PAPER)
				{
					cout << "컴퓨터 : 보" << endl;
					cout << "졌습니다!" << endl;
				}
				else if (cumNum == SCISSORS)
				{
					cout << "컴퓨터 : 가위" << endl;
					cout << "이겼습니다!" << endl;
					break;
				}
				else
				{
					cout << "컴퓨터 : 바위" << endl;
					cout << "비겼습니다!" << endl;
				}
			}

			else if (playerNum == PAPER)
			{
				cout << "나 : 보" << endl;
				if (cumNum == SCISSORS)
				{
					cout << "컴퓨터 : 가위" << endl;
					cout << "졌습니다!" << endl;
				}
				else if (cumNum == ROCK)
				{
					cout << "컴퓨터 : 바위" << endl;
					cout << "이겼습니다!" << endl;
					break;
				}
				else
				{
					cout << "컴퓨터 : 보" << endl;
					cout << "비겼습니다!" << endl;
				}
			}
		}
	}






	return 0;
}