#pragma once
#define Bar_Width 100.0f
#define Bar_Height 20.0f
#define Bar_Center_X  WIN_WIDTH * 0.5
#define Bar_Center_Y  WIN_HEIGHT - 150.0f

class Bar : public RectCollider
{
public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);

	void Move();

private:
	HBRUSH _brush;
};

