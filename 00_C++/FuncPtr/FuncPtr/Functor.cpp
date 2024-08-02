#include <iostream>

using namespace std;

// �Լ���ü
// ��ü�̰�, �Լ�ó�� �� �� �ִ�(()�Լ� �����ڸ� �����ε��ؼ� ���� �ִ�.) ��ü
// �ݹ鰳�����ε� �� �� �ִ�.
// -> �ٵ� �Լ� �����Ϳ� �ٸ� ��
// -> �Ӽ�(�������)�� ���� �� �ִ�.

struct Functor
{
	Functor()
	: _aInt(0), _bInt(0)
	{
	}

	// ������ �����ε�
	void operator()() // () �Լ� ������ : �Լ�ó�� �� �� �ִ�.
	{
		cout << "Hello World" << endl;
		cout << _aInt + _bInt << endl;
	}

	void operator()(int num)
	{
		cout << num << endl;
	}

	int _aInt;
	int _bInt;
};

class Player
{
public:
	void Excute()
	{
		if (_functor != nullptr)
		{
			(*_functor)();
		}
	}

	void SetFunctor(Functor* functor)
	{
		_functor = functor;
	}

private:
	Functor*_functor;
};



int main()
{
	Functor functor; // ��ü�� (�⺻������ ȣ��)
	functor._aInt = 1; // �Ӽ��� ��ĥ �� ����
	functor._bInt = 5;
	functor(); // �Լ� ��ü
	functor(1);

	return 0;
}