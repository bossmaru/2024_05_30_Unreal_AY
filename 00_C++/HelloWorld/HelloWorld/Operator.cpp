#include <iostream>

#define STURN		(1 << 0) // ���� �빮�ڷ� ��
#define SLEEP		(1 << 1)
#define AIRBONE		(1 << 2)
#define INVINSIBLE  (1 << 3)

using namespace std;

// ������
	// ��Ģ����
	// + - * / % -> �ڷ������� �ٸ� �� �ִ�.

// ������
	// + - * ...
	// / ... ���� ��ȯ
	// 10 / 3 => 3
	// % ... �������� ��ȯ -> ��ȯ ���� or ������ ���� ���� �� �߿�
	// 10 % 3 => 1

// �Ǽ���
	// + - * ����
	// / ... �׳� ���� -> ��ȯ�Ҽ��� �߰��� ©�� (�ε� �Ҽ����� ���� ����)
	// ���� 0���� ������ ������ �ܰ迡�� ���� ��
	// ���� 0���� ������ ����� �� -> inf�� ��

// = ���Կ�����
	// a = b : a���ٰ� b�� '����'�ϰ� a�� ������ ��ȯ�Ѵ�.
	// +=, -=, *=, /=

// ���������� (�Ǽ����� �Ǳ��ϴµ� ���� int)
	// ++, --
	// aInt++ / aInt-- ... ����������
	// aInt = bInt++;
	// -> aInt���ٰ� bInt�� ���� �����ϰ� bInt�� 1 �ø���.
	// ++aInt / --aInt ... ����������
	// aInt = ++bInt
	// -> bInt �� �켱 1 �ø��� �װ��� aInt���� �����Ѵ�.

// �񱳿�����
	// ��ȯ�ڷ����� bool
	// ==, !=, <, >, <=, >=
	// == ������ true
	// != �ٸ��� true

// ��������
	// ��ȯ�ڷ����� bool
	// !, &&,
	// ! : not
	// a && b : a�� true�̰� b�� true�̸� true
	// a || b : a, b  �� �߿� �ϳ��� true �� true

// ��Ʈ������ : ��ȣ ���� �������� ���δ�.
	// &, |, ^, >>, <<
	// a & b : ��Ʈ�� ���ڸ��� �� and ����
	// 1 & 2 : 0001 and 0010 = 0000 = 0
	// 1 & 3 : 0001 and 0011 = 0001 = 1
	// a | b : ��Ʈ�� ���ڸ��� �� or ����
	// 1 | 3 : 0001 or 0011 = 0011 = 3
	// a ^ b : xor ���� ... ��Ʈ�� ���� ���� ���� �� 1, ������ 0
	// 1 ^ 3 : 0001 xor 0011 = 0010 = 2
	
	// << : ���� Shift ����
	// Ư¡ : 2�谡 �ȴ�, �ǿ����� ��Ʈ�� �׻� 0���� ä������
	// �� ���� - �Ǵ°� ���� : ��ȣ ���� ������ ���
	// >> : ������ Shift ����
	// Ư¡ : �� ������ ��Ʈ�� �������� �ȴ�. 
	// ��ȣ�� �ִ� �������̶�� ���� ��ȣ��Ʈ�� �����ȴ�. 

// ��Ʈ�÷���
	// [����][����][���][����]
unsigned char state = 0;
const unsigned char sturn = 0b1000; // 1 << 3 
const unsigned char sleep = (1 << 2);
const unsigned char airbone = 2;
const unsigned char invinsible = 1;
//const -> ������

enum CC_State
{
	E_STURN =		(1 << 0),
	E_SLEEP =		(1 << 1),
	E_AIRBONE =		(1 << 2),
	E_INVINSIBLE =  (1 << 3)
};
// CC_State::E_STURN -> �ַ� �� ������� ��


// ��Ʈ����ũ
	// & (������� ��Ʈ)




int main()
{
#pragma region ������
	int aInt = 10;
	int bInt = 3;
	int cInt = 0;

	cInt = (aInt + bInt) % bInt;
	cout << cInt << endl;

	aInt += 1;

	cout << ++aInt << endl; // 12 ���
	cout << aInt++ << endl; // 12 ���
	cout << aInt << endl; // 13 ���

	aInt = ++bInt;
	aInt = bInt++;
	cout << aInt << endl; // 4 ���

	cout << (aInt == bInt) << endl; // false 0
	cout << ((aInt < bInt) > (aInt == bInt)) << endl; // true 1

	aInt = 2;
	bInt = 3;
	cInt = ++bInt; // 4

	bool check1 = (aInt > bInt); // 0
	bool check2 = (cInt != aInt); // 1
	bool check3 = !check1; // 1
	bool check4 = check3 || check2; // 1
	bool check5 = check2 && (check3 || check4); // 1

	cout << check1 << endl;
	cout << check2 << endl;
	cout << check3 << endl;
	cout << check4 << endl;
	cout << check5 << endl;

	cout << (1 & 3) << endl;
	cout << (1 | 3) << endl;
	// xor...
	// a ^ b ^ b = a ... ��ȣ�п��� �� �� ����
	aInt = 1;
	bInt = 3;
	cInt = (aInt ^ bInt);
	cout << (cInt ^ bInt) << endl; // 1 ����
	
	unsigned char u_aChar = 3;
	unsigned char u_bChar = (1 << 4); // 16
	unsigned char u_cChar = (u_aChar | u_bChar); // 19
	unsigned char u_dChar = (1 << 3) | (1 << 2); // 12
	unsigned char u_eChar = (u_cChar & u_dChar); // 0

#pragma endregion




#pragma region ��Ʈ�÷���
	state |= (E_STURN | SLEEP);
	if (state & STURN) // ��Ʈ����ũ
	{
		cout << "���ϻ����Դϴ�" << endl;
	}

	if (state & SLEEP)
	{
		cout << "��������Դϴ�" << endl;
	}

	if (state & (STURN | SLEEP))
	{
		cout << "����, ��������Դϴ�" << endl;
	}
#pragma endregion



	return 0;
}


// ĸ�� or ���� or ����...
// ���� 1
	// �޸� 4 ���� ����

// ���� 2
	// ����� �����ϴ� ���

// ���� 3
	// ����