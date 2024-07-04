#pragma once

enum class ItemType
{
	LongBar,
	DoubleBall,
	TripleBall,
};

class Item : public CircleCollider
{
public:
	Item();
	~Item();

	void Update();
	void Render(HDC hdc);

	void SetItemType(ItemType itemType);
	ItemType GetItemType() { return _itemType; }

private:
	ItemType _itemType;
	vector<HBRUSH> _brushes;
};


