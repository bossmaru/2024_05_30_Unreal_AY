#include <iostream>

using namespace std;


// Reference ����
// ���� ��� : (�ڷ���)&(���� �̸�) = (�ݵ�� �ʱ�ȭ)

// ������� �� �ϴ� ����� ������ ����

// ���� : C++ ���� ������ �����ִ� ���� (�׷��� �ݵ�� �ʱ�ȭ�ؾ���, ���� ������ ������ �ʿ���)


// Ptr�� ���� ����
// 1. nullptr�� ��Ÿ�� �� �ִ�... -> prt���� NULL���� ������ �� �ִ�. (�ƹ��͵� ���� �ּҸ� ���� �� �ִ�.)


// Ref�� ���� ����
// 1. ���ϴ�.(�����ڸ� ���� �� �ʿ䰡 ����.)-> �� ���ް� ����ϴ� ����� ����
// 2. NULL ǥ�ø� �� �� ����. (���� �Ұ�...)
// 3. ptr�� �����ϴ�.

struct Player
{
	int hp;
	int mp;
};

// �Ű������� ������ �ѱ��...Call by Reference
// �б����� : const ����
void PrintPlayer(const Player& player) // �����Ϳ� �Ѱ��ִ� ����Ʈ�� ����. 
{
	cout << player.hp << endl; // ���� ������ �ʿ� ����
	cout << player.mp << endl;
}


void SetPlayer(Player& player, int hp, int mp)
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{

#pragma region ����
	int aInt = 1;

	// ����
	int& aRef = aInt; //aInt�� ������ aRef
	// ������
	int* aPtr = &aInt;


	*aPtr = 10;
	cout << aInt << endl;

	aRef = 11;
	cout << aInt << endl;
#pragma endregion


	Player p;
	p.hp = 0;
	p.mp = 0;

	// �÷��̾ ���
	Player* p_ptr = nullptr; // ������ �̰� �ȵ�(0�� ���� ���� �ȵ�)

	SetPlayer(p, 100, 100);
	PrintPlayer(p);


	return 0;
}