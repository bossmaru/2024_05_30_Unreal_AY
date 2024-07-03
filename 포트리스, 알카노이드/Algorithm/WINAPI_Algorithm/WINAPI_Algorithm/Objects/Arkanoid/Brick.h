#pragma once

#define BRICK_WIDTH  WIN_WIDTH * 0.06f
#define BRICK_HEIGHT 25.0f


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

