#include <iostream>

using namespace std;


// 과제 2
	// 가위바위보 게임 만들기
	// 1 -> 가위, 2 -> 바위, 3 -> 보
	// 숫자를 1~3 입력받는다. (단, 다른 수를 입력하면 다시)
	// 컴퓨터가 1~3까지 숫자를 랜덤하게 갖고 있습니다.
	// 누가 어떤 거 냈는지 출력
	// 이 모든 과정을 내가 이길 때 까지 반복

	// (선택과제)... 자유롭게 함수화







 void Name(int num)
{
	if (num == 1)
	{
		cout << "가위" << endl;
	}
	else if(num == 2)
	{
		cout << "바위" << endl;
	}
	else if (num == 3)
	{
		cout << "보" << endl;
	}

	return;
}


void Print(int me, int computer)
{
	int result = me - computer;
	if (result == -2 or 1)
	{
		cout << "나 : ";
		Name(me);
		cout << endl;
		cout << "컴퓨터 : ";
		Name(computer);
		cout << endl;
		cout << "이겼습니다!" << endl;

	}
}

void Lose(int me, int computer)
{
	int result = me - computer;
	if (result == -1 or 2)
	{
		cout << "나 : ";
		Name(me);
		cout << endl;
		cout << "컴퓨터 : ";
		Name(computer);
		cout << endl;
		cout << "졌습니다!" << endl;

	}
}

void Draw(int me, int computer)
{
	int result = me - computer;
	if (result == 0)
	{
		cout << "나 : ";
		Name(me);
		cout << endl;
		cout << "컴퓨터 : ";
		Name(computer);
		cout << endl;
		cout << "비겼습니다!" << endl;

	}
}

int main()
{

	srand(time(NULL));
	int playerNum = 0;
	int comNum = 0;

	//  컴퓨터가 1~3까지 랜덤한 수 갖고 있음.
	comNum = (rand() % 3 + 1);

	// 숫자 1~3을 입력받는다.
	cout << "1~3까지의 숫자를 입력해주세요." << endl;


	// 이길 때까지 반복
	while (true)
	{
		cin >> playerNum;

		// 잘못 입력한 경우
		if ((playerNum != 1) && (playerNum != 2) && (playerNum != 3))
		{
			cout << "다시 입력해주세요" << endl;
		}

		// 제대로 입력한 경우
		else
		{

		}


	return 0;
}