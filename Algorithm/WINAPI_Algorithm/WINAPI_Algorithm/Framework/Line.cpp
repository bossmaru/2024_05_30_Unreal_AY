#include "pch.h"
#include "Line.h"

Line::Line(Vector2 start, Vector2 end)
: _start(start), _end(end)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{

	SelectObject(hdc, _curPen);
	MoveToEx(hdc, _start._x, _start._y, nullptr);
	LineTo(hdc, _end._x, _end._y);
}

void Line::Projection1(shared_ptr<class Line> other)
{
	_end._x = other->_end._x;
}

void Line::Projection2(shared_ptr<class Line> land, shared_ptr<class Line> other)
{
	Vector2 other_vector = other->_end - other->_start;
	Vector2 land_vector = land->_end - land->_start;
	float length = other_vector.Dot(land_vector) / land_vector.Length();

	_end._x = land_vector.NormalVector2()._x * length + _start._x;
	_end._y = land_vector.NormalVector2()._y * length + _start._y;
}

bool Line::IsCollision(shared_ptr<Line> other)
{
	Vector2 me = _end - _start;
	Vector2 other_vector= other->_end - other->_start;

	bool con1 = me.IsBetween(other->_start - _start, other->_end - _end);
	bool con2 = other_vector.IsBetween(_start - other->_start, _end - other->_start);


	if (con1 && con2)
	{
		return true;
	}

	return false;
}

Vector2 Line::CollisionPoint(shared_ptr<Line> other)
{
	Vector2 new_end = Vector2(0, 0);
	Vector2 me = _end - _start;
	Vector2 other_vector = other->_end - other->_start;
	Vector2 start_to_start = _start - other->_start;

	if (IsCollision(other))
	{
		float sin1 = me.Cross(other_vector) / (me.Length() * other_vector.Length());
		float sin2 = other_vector.Cross(start_to_start) / (other_vector.Length() * start_to_start.Length());

		float length = start_to_start.Length() * sin2 / sin1;

		new_end = me.NormalVector2() * length + _start;

		// 넓이로 해도 됨!
		// 선형보간법
	}

	return new_end;
}
