#include <iostream>

using namespace std;  //standard library

//  bit : 0�� 1�� ����Ǵ� �ּҴ���
//  byte : 8bit

// �ڷ���(DataType)
// ���� (�ٱ���)
// ���� ������
	// (�ڷ���) (�����̸�) = �ʱ�ȭ

// ������
	// short -> 2byte = 16bit (-2^15 ~ 2^15-1) (2^16��, 0����) -> (-32768 ~32767)
	// int  -> 4byte = 32bit (-2^31 ~ 2^31-1) (2^32��) -> (�� -21�� ~ 21��)
	// long long(int64) __int64 -> 8byte (-2^63 ~ 2^63-1) (2^64��)

// ���� ���� ����� ��� (2�� ������)
	// 1. ��Ʈ�� ��� �ڹٲ۴�.
	// 2. +1�� �Ѵ�.

// ������ �����÷ο�, ����÷ο�
	// short aShort = -32768 - 1 -> 32767
	// short aShort = 32767 + 1 -> -32768

// �Ǽ���
	// float ->  4byte = 32bit
	// (��ȣ 1�ڸ�) + (���� 8�ڸ�) + (��ȿ���� 23�ڸ�)
	// (0.125 = 1 * 2^-3)
	// double -> 8byte
	// ����Ǵ� ��� : �ε��Ҽ���
	
// ����
	// bool -> 1byte (�ý��� �ּ�ó�������� 1byte�� ��¿�� ����..)
	// true 1 / false 0
		// 0�� �����ϸ� false, �� �ܿ� ��� ���� �� true

// ������
	// char : 1byte
	// 2^8 = 256������ ���ĺ�, ���ڸ� ǥ���� �� �ִ�. -> �ƽ�Ű�ڵ�
	// �����ڵ� (wchar)
	// - UTF-8 : ���ĺ�, ����(1byte) / �ѱ�, �߱���(3byte)
	// - UTF-16 : ���ĸ�, ����, �ѱ�, �߱���(2byte) / ��빮��(4byte)

// Escape Sequence
	// \t : ��
	// \n : �ٹٲ�
	// \" : "
	// \0 : NULL ǥ�� = 0�̶�� ��

// ��ȣ�ΰ� ���� �ڷ���
unsigned int u_aInt = 5; // 0 ~ 2^32-1
unsigned short u_aShort = 1; // 0 ~ 2^16-1

// ����� ���� �ڷ���
struct Pos
{
	int x;
	short y; // �굵 ��� 4byte�� ó��
	short padding = 0; // �����Ⱚ 0����..
};




int main() // ���� �Լ�
{
	// ������
	int aInt = 1;
	__int64 aInt64 = 241313;
	short aShort = -32768 - 1; // 32767 ���� (������ �����÷ο찡 �Ͼ��)

	//�Ǽ���
	float aFloat = 1.25f; // f�ٿ���
	double aDouble = 1.222;

	// ����
	bool aBool = -1; // ����غ��� 1 ����
	cout << aBool << endl;

	// ������
	char aChar = 97; // ����ϸ� ���ڷ� ���� (a)
	cout << aChar << endl;

	// ����� ���� �ڷ���
	Pos aPos;
	aPos.x = 1;
	aPos.y = 2;


	Pos bPos;
	bPos.x = 3;
	bPos.y = 3;



	//��º�
	cout << "short�� ũ�� " << sizeof(aShort) << endl; // endl : �ٹٲ� = \n
	cout << "int�� ũ�� " << sizeof(aInt) << endl;
	cout << "int64�� ũ�� " << sizeof(aInt64) << endl;
	cout << "float�� ũ�� " << sizeof(aFloat) << endl;
	cout << "double�� ũ�� " << sizeof(aDouble) << endl;
	cout << "bool�� ũ�� " << sizeof(aBool) << endl;

	cout << "Pos�ڷ����� ũ�� " << sizeof(aPos) << endl;

	int sum = aInt + 5;
	// Pos cPos = aPos + bPos; -> �Ұ���

	return 0;

}