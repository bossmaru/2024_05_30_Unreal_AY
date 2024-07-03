#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;


struct Item
{
	Item(int price, int tier, int atk) : price(price), tier(tier), atk(atk) {}

	int price;
	int tier;
	int atk;
};

// ���� �Լ�
// [] () -> {}
// [ĸ�� : �ܺ� ������ �����ؼ� ����ϴ� �κ�]
// (�Ű�����)
// -> ��ȯ �ڷ���
// {�Լ���}

int main()
{
	srand(time(nullptr));

	vector<Item*> items;

	for (int i = 0; i < 10; i++)
	{
		int tier = rand() % 10;
		Item* item = new Item(tier * 100, tier, tier * 5);
		items.push_back(item);
	}


	struct TierFinder
	{
		bool operator()(Item* item)
		{
			if (item->tier == tier)
				return true;
			return false;
		}
		
		int tier;
	};

	TierFinder tf;
	tf.tier = 0;

	// Call able ��ü
	items.erase(std::remove_if(items.begin(), items.end(), tf), items.end());

	int capture = 1;
	int* capture_ptr = new int(1);                       // = : ���� �ִ� ���������� ��� ĸ���ذ���.
	items.erase(std::remove_if(items.begin(), items.end(), [=](const Item* item)-> bool
	{
			if (item->tier == capture)
				return true;
			return false;

	}), items.end());


	// Items�� ���ݼ����� ������������ �������ּ���.
	std::sort(items.begin(), items.end(), [](Item*item1, Item*item2)->bool
		{
			return (item1->price > item2->price);
		});


	return 0;
}