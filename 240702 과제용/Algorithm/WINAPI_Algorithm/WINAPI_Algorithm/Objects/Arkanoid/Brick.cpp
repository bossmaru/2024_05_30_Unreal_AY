#include "pch.h"
#include "Brick.h"

Brick::Brick()
: RectCollider(Vector2(), Vector2(BrickWidth * 0.5, BrickHeight * 0.5))
{
	_brush = CreateSolidBrush(SKYCOLOR);
}

Brick::~Brick()
{
	DeleteObject(_brush);
}

void Brick::Update()
{
	RectCollider::Update();
}

void Brick::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);
}

void Brick::SetPosition(Vector2 pos)
{
	_center = pos;
}
