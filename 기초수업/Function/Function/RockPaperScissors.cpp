#include <iostream>

using namespace std;

// �ַ�� : ����
// ������Ʈ : ����
// ���� : å



enum RSP
{
	SCISSORS = 1,
	ROCK = 2,
	PAPER = 3
};


int main()
{
	
	srand(time(NULL));
	// ���� 2
	// ���������� ���� �����
	// 1 -> ����, 2 -> ����, 3 -> ��
	// ���ڸ� 1~3 �Է¹޴´�. (��, �ٸ� ���� �Է��ϸ� �ٽ�)
	// ��ǻ�Ͱ� 1~3���� ���ڸ� �����ϰ� ���� �ֽ��ϴ�.
	// ���� � �� �´��� ���
	// �� ��� ������ ���� �̱� �� ���� �ݺ�

	// (���ð���)... �����Ӱ� �Լ�ȭ



	// ���� 3
	// ������ ���� �����
	// 1. ��ǻ�Ͱ� 1~500������ ������ ���� ���� �ִ´�.
	// 2. �÷��̾ 1~500������ ���� �Է� �޴´�. �� �ٸ� ���� �Է��ϸ� �ٽ�
	// 3. �÷��̾ �Է��� ���� ��ǻ���� ���� ������ �� ��Ҹ� ���
	// ����) ��ǻ�� 250, �÷��̾� 100 -> �÷��̾��� ���� �� �۽��ϴ�.
	// 4. �̸� 9�� �ݺ�, ���߸� ��
	// 5. ���ߴ� ����� ����ؿ�����.

	// (���ð���)...�����Ӱ� �Լ�ȭ


	// ���� 4
	// �����Ϳ� ������ ���ؼ� �����غ��ÿ�.

	int playerNum = 0;
	int cumNum = 0;

	// ���� 1~3�� �Է¹޴´�.
	cout << "1~3������ ���ڸ� �Է����ּ���." << endl;

	//  ��ǻ�Ͱ� 1~3���� ������ ��
	cumNum = (rand() % 3 + 1);


	// �߸� �Է��� ���
	while (true)
	{
		cin >> playerNum;
		if (playerNum < 1 or playerNum > 3)
		{
			cout << "�ٽ� �Է����ּ���" << endl;
		}

		// ����� �Է��� ���
		else
		{
			if (playerNum == SCISSORS)
			{
				cout << "�� : ����" << endl;
				if (cumNum == ROCK)
				{
					cout << "��ǻ�� : ����" << endl;
					cout << "�����ϴ�!" << endl;
				}
				else if (cumNum == PAPER)
				{
					cout << "��ǻ�� : ��" << endl;
					cout << "�̰���ϴ�!" << endl;
					break;
				}
				else
				{
					cout << "��ǻ�� : ����" << endl;
					cout << "�����ϴ�!" << endl;
				}
			}

			else if (playerNum == ROCK)
			{
				cout << "�� : ����" << endl;
				if (cumNum == PAPER)
				{
					cout << "��ǻ�� : ��" << endl;
					cout << "�����ϴ�!" << endl;
				}
				else if (cumNum == SCISSORS)
				{
					cout << "��ǻ�� : ����" << endl;
					cout << "�̰���ϴ�!" << endl;
					break;
				}
				else
				{
					cout << "��ǻ�� : ����" << endl;
					cout << "�����ϴ�!" << endl;
				}
			}

			else if (playerNum == PAPER)
			{
				cout << "�� : ��" << endl;
				if (cumNum == SCISSORS)
				{
					cout << "��ǻ�� : ����" << endl;
					cout << "�����ϴ�!" << endl;
				}
				else if (cumNum == ROCK)
				{
					cout << "��ǻ�� : ����" << endl;
					cout << "�̰���ϴ�!" << endl;
					break;
				}
				else
				{
					cout << "��ǻ�� : ��" << endl;
					cout << "�����ϴ�!" << endl;
				}
			}
		}
	}






	return 0;
}