#include <iostream>

using namespace std;

struct Item
{
	void PrintItem()
	{
		cout << "Price : " << price << endl;
		cout << "Tier : " << tier << endl;
		cout << "Atk : " << atk << endl;
	}

	int price;
	int tier;
	int atk;
};

// �Լ� �����͸� �̿��ؼ� ã�� ���
Item* FindItem_FuncPtr(Item* arr, int size, bool(*func)(const Item&))
{
	Item* result = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]))
			result = &arr[i];
	}

	return result;
}

bool FindItemPtr_Price(const Item& item)
{
	if (item.price == 1500)
		return true;

	return false;
}

bool FindItemPtr_Tier(const Item& item)
{
	if (item.tier == 8)
		return true;

	return false;
}

// �Լ� ��ü�� ã�� ���
struct Finder_1
{
	bool operator()(const Item& item)
	{
		if (itemPrice == item.price && itemTier == item.tier)
			return true;
		return false;
	}

	int itemPrice;
	int itemTier;
};

struct Finder_2
{
	bool operator()(const Item& item)
	{
		if (itemAtk == item.atk && itemTier == item.tier)
			return true;
		return false;
	}

	int itemAtk;
	int itemTier;
};

struct Finder_ALL
{
	bool operator()(const Item& item)
	{
		if (itemPrice == item.price && itemTier == item.tier && itemAtk == item.atk)
			return true;
		return false;
	}

	int itemPrice;
	int itemTier;
	int itemAtk;
};


template <typename I, typename T>
I* FindItem_Functor(I* arr, int size, T finder)
{
	Item* result = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (finder)
			result = &arr[i];
	}

	return result;
}

int main()
{
	Item items[10];
	for (int i = 0; i < 10; i++)
	{
		items[i].price = 500 * (i + 1) * 3;
		items[i].tier = (10 - i);
		items[i].atk = 10 * (i + 1);
	}

	// �Լ� �����͸� ����ؼ�
	// tier�� 8�� �ָ� ã�Ƽ� ���
	Item* findItem = nullptr;
	findItem = FindItem_FuncPtr(items, 10, &FindItemPtr_Tier);
	if (findItem != nullptr)
		findItem->PrintItem();

	// �Լ� ��ü�� ����ؼ�
	// price�� 9000�̰� tier�� 5 ã�Ƽ� ���
	Finder_1 finder;
	finder.itemPrice = 9000;
	finder.itemTier = 5;
	findItem = FindItem_Functor<Item, Finder_1>(items, 10, finder);
	if (findItem != nullptr)
		findItem->PrintItem();


	// �Լ� ��ü�� ����ؼ�
	// price 3000, tier 9, atk 20 ã�Ƽ� ���
	Finder_ALL finder_all;
	finder_all.itemPrice = 3000;
	finder_all.itemTier = 9;
	finder_all.itemAtk = 20;
	findItem = FindItem_Functor<Item, Finder_ALL>(items, 10, finder_all);
	if (findItem != nullptr)
		findItem->PrintItem();


	Finder_2 finder_2;
	finder_2.itemTier = 9;
	finder_2.itemAtk = 20;
	findItem =  FindItem_Functor<Item, Finder_2>(items, 10, finder_2);
	if (findItem != nullptr)
		findItem->PrintItem();




	return 0;
}