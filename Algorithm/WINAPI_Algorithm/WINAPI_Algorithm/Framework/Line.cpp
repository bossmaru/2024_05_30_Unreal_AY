#include "pch.h"
#include "Line.h"

Line::Line(Vector2 start, Vector2 end)
: _start(start), _end(end)
{
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	MoveToEx(hdc, _start._x, _start._y, nullptr);
	LineTo(hdc, _end._x, _end._y);
}

void Line::contour(shared_ptr<class Line> other)
{
	_end._x = other->_end._x;
}

void Line::contour2(shared_ptr<class Line> land, shared_ptr<class Line> other)
{
	Vector2 other_vector = other->_end - other->_start;
	Vector2 land_vector = land->_end - land->_start;
	float length = other_vector.Dot(land_vector) / land_vector.Length();

	_end._x = land_vector._x * length / land_vector.Length() + _start._x;
	_end._y = land_vector._y * length / land_vector.Length() + _start._y;
}

