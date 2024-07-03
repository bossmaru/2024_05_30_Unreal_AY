#include <iostream>

using namespace std;

// ������ ... Pointer (�ڷ����� ����)
// ����Ű�� ��
// �ּҸ� ����ִ� ����
// (�ڷ���)*(�����ͺ����̸�) = (�ʱ�ȭ - �ص��ǰ� ���ص� ��);
// (�ڷ���) : ������ Ÿ�� ���� �� �ش� �ڷ����� ���� ���̴� ��� ��Ʈ

// ũ�� : 32��Ʈ �ü�� ���α׷������� 4����Ʈ, 64��Ʈ �ü�� ���α׷������� 8����Ʈ

// ������
// &(�����̸�) : �ּҿ����� -> �� ������ �ּҰ��� ������
// *(�����ͺ���) : ����������...��Ż������

// void* : Ÿ����� ���� �ڷ����� �ִ� �������.


// �Ű������� �� ��
// Call by Value
void AddOne(int num)
{
	num++;

	return;
}

// �Ű������� �� '�ּҰ�'
// Call by Address
void AddOne(int*ptr)
{
	(*ptr)++; // aInt + 1

	return;
}



int main()
{
	int aInt = 5; // 

	int* aPtr = &aInt;
	//������ Ÿ�� ���� int���� �ڷᰡ ���� ���̴�.

	cout << "aInt�� �ּ�" << &aInt << endl; // ��¼��
	cout << "aInt ������ ��� �ִ� ��" << aInt << endl; // 5
	cout << "aPtr�� �ּ�" << &aPtr << &aPtr << endl; // ���ο� �ּ�
	cout << "aPtr ������ ��� �ִ� ��" << aPtr << endl; // ��¼��� ����

	cout << *aPtr << endl; // ���������� ... ��Ż������ // 5 ���
	*aPtr = 6;

	cout << aInt << endl; // 6 ����

	float* bPtr = (float*)& aInt; // aInt �ڷ����� float���� �ٲ�� ���� �ȳ�...�׳� ����


	// void*
	void* vPtr = &aInt;

	aInt = 0;
	AddOne(&aInt);

	cout << aInt << endl;


	return 0;
}