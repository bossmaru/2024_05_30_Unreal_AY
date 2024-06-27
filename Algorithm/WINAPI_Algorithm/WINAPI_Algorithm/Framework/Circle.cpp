#include "pch.h"
#include "Circle.h"

CircleCollider::CircleCollider(Vector2 center, float radius)
: _center(center), _radius(radius)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GREEN_COLOR);
}

CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}


void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);

	int left = _center._x - _radius;
	int top = _center._y - _radius;
	int right = _center._x + _radius;
	int bottom = _center._y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(Vector2 point)
{
	float distance = _center.Distance(point);
	return distance <= _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance <= (_radius + other->_radius);
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	int rect_left = other->Left();
	int rect_top = other->Top();
	int rect_right = other->Right();
	int rect_bottom = other->Bottom();

	bool con1 = (_center._x >= rect_left - _radius && _center._x <= rect_right + _radius && _center._y <= rect_bottom && _center._y >= rect_top);
	bool con2 = (_center._x >= rect_left && _center._x <= rect_right && _center._y <= rect_bottom + _radius && _center._y >= rect_top - _radius);
	bool con3 = (_center.Distance(Vector2(rect_left, rect_top)) <= _radius || _center.Distance(Vector2(rect_left, rect_bottom)) <= _radius || _center.Distance(Vector2(rect_right, rect_top)) <= _radius || _center.Distance(Vector2(rect_right, rect_bottom)) <= _radius);

	return ((con1 || con2) || con3);
}

void CircleCollider::SetColor(ColorNum num)
{
	_curPen = _pens[num];
}
