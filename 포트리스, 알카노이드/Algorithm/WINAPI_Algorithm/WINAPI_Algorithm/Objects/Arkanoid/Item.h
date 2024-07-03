#pragma once
class Item : public CircleCollider
{
public:
	Item();
	~Item();

	void Update();
	void Render(HDC hdc);

private:
	// vector<HBRUSH> _brushes;
};

