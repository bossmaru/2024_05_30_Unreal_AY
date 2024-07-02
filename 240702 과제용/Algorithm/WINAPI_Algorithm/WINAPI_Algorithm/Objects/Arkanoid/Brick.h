#pragma once

#define BrickWidth  WIN_WIDTH * 0.1
#define BrickHeight 25.0f

class Brick : public RectCollider
{
public:
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);

	void SetPosition(Vector2 pos);
	bool _shoot = false;

private:
	// vector<HBRUSH> _brushes;
	HBRUSH _brush;
};

