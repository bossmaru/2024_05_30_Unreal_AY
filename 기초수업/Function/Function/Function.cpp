#include <iostream>

using namespace std;


// �Լ�
	// ��ȯ���� �Լ��̸� (�Ű�����)
	// {
	//		�Լ� ����
	// 
	//		return (��ȯ��);
	// }


// void : �ڷ����� ���� (���� ������ ����)

// �Լ� ȣ��
// �Լ��̸�(�Ű�����)

// ȣ�⽺��
// ���� : ������ũ ����, ž�ױ�


// �Լ� �����ε� : �Լ��� �̸��� ���Ƶ�, �Ű������� ������ ������Ÿ���� �ٸ��� ���...��ȯ������ �޶� ���

// �Լ��� ���� ����
	// 1. ���뼺
	// 2. �ڵ� ������(�Լ� �̸� �߿�)


void HelloFunc(void)
{

	cout << "Hello Function" << endl; // �׳� �̰͸����δ� �ȶ�. �Լ� ȣ���ؾ���

	return; // ���ϰ��� ����
}


void PrintNum(int num)
{
	cout << num << endl;

	return;
}

int AddOne(int num)
{
	// main([��ȯ�ּҰ�][aInt(��������)][�Ű����� ����]) AddOne([��ȯ�ּҰ�][�������� ����][num(�Ű�����)]
	num++;

	return num;
}

void SumNum(int num1, int num2)
{
	int sum = num1 + num2;
	cout << sum << endl;

	return;
}


// �Լ� �����ε�
void SumNum(int num1, int num2, int num3) // �Լ� �̸� ����, �Ű����� ���� �ٸ�
{
	int sum = num1 + num2 + num3;

	cout << sum << endl;

}


// �Լ��� �⺻ ����
void SumNum(int num1, int num2, int num3, int num4, int num5 = 0)
{
	int sum = num1 + num2 + num3 + num4;

	cout << sum << endl;

}


void Stars(int input)
{
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

// ���ȣ���� �ϴ� �Լ�
// ���ÿ����÷ο쿡 ��������
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}


int main(void) // void �����ص� ��
{

	Stars(5);

	int aInt = 1;
	aInt = AddOne(aInt);


	return 0;
}