#include "pch.h"
#include "Ball.h"

Ball::Ball()
:CircleCollider(Vector2(Bar_Center_X, Bar_Center_Y - Bar_Height - Ball_Radius), Ball_Radius)
{
	_brush = CreateSolidBrush(RED);
}

Ball::~Ball()
{
	DeleteObject(_brush);
}

void Ball::Update()
{
	CircleCollider::Update();
	if (GetAsyncKeyState(VK_SPACE))
	{
		_start = true;
	}

	if (_start)
	{
		_center += _direction * _speed;
	} 
}

void Ball::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	CircleCollider::Render(hdc);
}
