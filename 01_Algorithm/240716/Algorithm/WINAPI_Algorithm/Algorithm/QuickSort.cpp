#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// Heap Sort
// 힙트리에 하나씩 다 집어넣고 하나씩 꺼낸다.


// Quick Sort
// 평균 시간 복잡도 : N x logN
// 최악 시간 복잡도 : N^2

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;

	while (true)
	{
		if (lowIndex > highIndex)
			break;

		// low Index는 항상 pivot보다 작아야한다.
		// 작으면 다음 index를 확인한다.
		while (lowIndex <= right && pivot >= v[lowIndex])
		{
			lowIndex++;
		}

		// high Index는 항상 pivot보다 커야한다.
		// 크면 이전 index를 확인한다.
		while(highIndex >= left + 1 && pivot <= v[highIndex])
		{
			highIndex--;
		}

		if(lowIndex < highIndex)
			std::swap(v[lowIndex], v[highIndex]);
	}

	std::swap(v[highIndex], v[left]);

	return highIndex;
}

void QuickSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int pivotIndex = Partition(v, left, right);
	cout << left << " ~ " << pivotIndex - 1 << endl;

	QuickSort(v, left, pivotIndex - 1);
	QuickSort(v, pivotIndex + 1, right);
}


int main()
{
	vector<int> v = { 55, 30, 15, 100, 1, 5, 70 };
	QuickSort(v, 0, v.size() - 1);

	// std::sort(v.begin(), v.end());
	// std::partial_sort(v.begin(), v.begin() + 3, v.end());

	return 0;
}