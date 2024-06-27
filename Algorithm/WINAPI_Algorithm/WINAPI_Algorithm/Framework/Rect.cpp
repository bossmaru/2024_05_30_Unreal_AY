#include "pch.h"
#include "Rect.h"

#define GREEN_COLOR 0
#define RED_COLOR   1

RectCollider::RectCollider(Vector2 center, Vector2 halfSize)
: _center(center), _halfSize(halfSize)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GREEN_COLOR);
}

RectCollider::~RectCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	int rect_left = Left();
	int rect_top = Top();
	int rect_right = Right();
	int rect_bottom = Bottom();

	Rectangle(hdc, rect_left, rect_top, rect_right, rect_bottom);
}

bool RectCollider::IsCollision(Vector2 point)
{
	int rect_left = Left();
	int rect_top = Top();
	int rect_right = Right();
	int rect_bottom = Bottom();

	return (point._x >= rect_left && point._x <= rect_right && point._y <= rect_bottom && point._y >= rect_top);
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	return other->IsCollision(shared_from_this());
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	int rect_left = Left();
	int rect_top = Top();
	int rect_right = Right();
	int rect_bottom = Bottom();

	return (other->_center._x >= rect_left - other->_halfSize._x && other->_center._x <= rect_right + other->_halfSize._x && other->_center._y <= rect_bottom + other->_halfSize._y && other->_center._y >= rect_top - other->_halfSize._y);
}

void RectCollider::SetColor(ColorNum num)
{
	_curPen = _pens[num];
}

