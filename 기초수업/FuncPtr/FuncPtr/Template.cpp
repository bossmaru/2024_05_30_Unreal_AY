#include <iostream>

using namespace std;

// Template
// 
// Class
// -> ��ü(�ǹ�)�� ���� ���赵
// Template�� ���赵�� ���� ��
//
// �Լ� ���ø� : �Լ��� ���� ��
// ���ø� �⺻���� (���� ���� ���ϸ� �װɷ� �������)
// ���ø��� Ư��ȭ
template <typename T = int> // class T ��� �ᵵ �� (� �ڷ��� T��� ��)
T Add(T a, T b)
{
	T c = a + b;

	return c;
}

template <>
double Add(double a, double b)
{
	double c = a + b;

	cout << "Double" << endl;

	return c;
}

// Ŭ���� ���ø�
template <typename T = int> // Ŭ���� ���ø� �⺻����
class Player
{
public:
	T getHp()
	{
		return _hp;
		// return _mp�� �ȵ�
	}

	void SetHp(const T& hp)
	{
		_hp = hp;
	}

	T _hp;
	int _mp;
};

// Ŭ���� ���ø� Ư��ȭ
template<>
class Player<double>
{
public:
	double _hp;
};


int main()
{
	double c = Add<double>(1.2, 2.5);

	cout << c << endl;

	Player<int>player;

	Player<double>player2; // _hp �ۿ� �� ��
	

	return 0;
}