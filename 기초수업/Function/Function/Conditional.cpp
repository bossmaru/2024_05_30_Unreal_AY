#include <iostream>

using namespace std;

// ���ǹ�
	// if��
	// if(������(true / false))
	// {
	//		���๮
	// }
	// else if(������)
	// {
	//		���๮
	// }
	// else
	// {
	//		���๮
	// }

	// swtich��
	// switch(���� ������)
	// {
	//		case 1: { ���๮ break: }
	//		case 2: { ���๮ break: }
	//		case ...: { ���๮ break: }
	// 
	//		default:
	//		{
	//		}
	// }


// �ݺ���
	// while��
	// while(������)
	// {
	//		if��(�����)
	//			continue;  ���๮�� ����Ǳ� ���� ���� ���� Ÿ�ּ���.
	//		���๮
	//		�����
	//		break;
	// }
	
	// for��
	// for(�ʱ��; ���ǽ�; �����)
	// {
	//		continue;
	//		���๮;
	//		break;
	// }

int main()
{
	int aInt = 3;
	int bInt = 3;

#pragma region ���ǹ�
	if (aInt > bInt)
	{
		cout << "aInt�� bInt���� Ů�ϴ�." << endl;
	}
	else if (aInt = bInt)
	{
		cout << "aInt�� bInt�� �����մϴ�." << endl;
	}
	else
	{
		cout << "aInt�� bInt���� �۽��ϴ�." << endl;
	}


	// ������ (�ڷ���)
	enum Test
	{
		ONE = 1,
		TWO,
		THREE
	};

	Test aTest = ONE;

	switch (aTest)
	{
	case ONE:
		break;
	case TWO:
		break;
	case THREE:
		break;
	default:
		break;
	}



	switch (aInt) // ���������� �����ؼ� enum�̶� ���� �� ����
	{
	case 1:
	{
		cout << "aInt�� 1�Դϴ�." << endl;
		break;
	}
	case 3:
	{
		cout << "aInt�� 3�Դϴ�." << endl;
		break; // break �Ȱɸ� ����Ʈ ���
	}
	
	default:
	{
		cout << "aInt�� ���� �� �𸣰ڽ��ϴ�." << endl;
		break;
	}
	}
#pragma endregion



#pragma region �ݺ���
	aInt = 0;
	while (true)
	{
		if (aInt == 3)
		{
			aInt++;
			continue;
		}


		cout << "�ݺ�!" << aInt <<  endl;

		aInt++; // �����
		if (aInt == 5)
			break;
	}


	for (int i = 0; i < 10; i++)
	{
		if (i == 3) continue;
		cout << i << "�� �ݺ�!" << endl;
		if (i == 5) break;
	}
#pragma endregion

	// �ǽ� 1
	// 5 �Է��ϸ�
	// *
	// *
	// *
	// *
	// *

	int input = 0;
	cin >> input;

	cout << input << endl;


	for (int i = 0; i < input; i++)
	{
		cout << "*" << endl;
	}


	// �ǽ� 2
	// 3 �Է��ϸ�
	// ***
	// ***
	// ***


	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		} 
		cout << endl;
	}


	// ���� 1 �����ﰢ�� �����
	// 5
	// *
	// **
	// ***
	// ****
	// *****


	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// ��ǻ�Ͱ� ������ ���� �ϴ� ���
	srand(time(NULL)); // �ܿ�� -> ���� �ð� �ִ� ��
	int randNum = rand(); // 0 ~ 32767 ���� �߿� ����
	// 1 ~ 3  ���� ������ �ϰ�ʹٸ�
	int randNum_3 = randNum % 3 + 1;
	cout << randNum_3 << endl;


	// �ǽ� 3
	// ���������� ���� �����
	// ���ڸ� 1~3 �Է¹޴´�.
	// ��ǻ�Ͱ� 1~3���� ���ڸ� �����ϰ� ���� �ֽ��ϴ�.
	// 1 -> ����, 2 -> ����, 3 -> ��






	return 0;
}