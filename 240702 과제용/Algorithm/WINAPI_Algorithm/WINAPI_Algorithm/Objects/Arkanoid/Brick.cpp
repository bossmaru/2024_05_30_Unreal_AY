#include "pch.h"
#include "Brick.h"

Brick::Brick()
: RectCollider(Vector2(), Vector2(BRICK_WIDTH * 0.5, BRICK_HEIGHT * 0.5))
{
	_brush = CreateSolidBrush(PANTON);
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
