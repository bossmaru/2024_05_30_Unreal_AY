#include <iostream>

using namespace std;


int lotto[45] = {}; // 45���� 0���� �ʱ�ȭ ��

// �տ��� �Լ� ���� �س��� �� ���� ->  ���� �ȳ�
void Swap(int& a, int& b);
void Shuffle(int arr[], int size, int count);
void SelectionSort(int arr[], int begin, int end);
void PrintArr(int arr[], int size);


void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void Shuffle(int arr[], int size, int count)
{

	for (int i = 0; i < count; i++)
	{
		int a = rand() % 45;
		int b = rand() % 45;

		Swap(arr[a], arr[b]);
	}
	
}



void SetLotto(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}

	Shuffle(arr, size, 10000);
	SelectionSort(arr, 0, 7);
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}


// ��������
void SequencialSort(int arr[], int begin, int end)
{
	for (int i = begin; i < end - 1; i++)
	{
		for (int j = i + 1; j < end; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}


}


void SelectionSort(int arr[], int begin, int end)
{
	for (int i = begin; i < end - 1; i++)
	{
		int best = i;
		for (int j = i + 1; j < end; j++)
		{
			if (arr[best] > arr[j])
			{
				best = j;
			}
		}

		if (best != i)
		{
			Swap(arr[i], arr[best]);
		}
	}

}

void BubbleSort(int arr[], int begin, int end)
{
	for (int i = end; i > begin; i--)
	{
		for (int j = begin; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// ���� 1
// ��ü������ 3�Ӽ�
// ���м�
// ������
// ���

// �����Լ�
// VF table
// RTTI

 

int main()
{
	srand(time(NULL));

	SetLotto(lotto, 45);
	PrintArr(lotto, 7);



	return 0;
}