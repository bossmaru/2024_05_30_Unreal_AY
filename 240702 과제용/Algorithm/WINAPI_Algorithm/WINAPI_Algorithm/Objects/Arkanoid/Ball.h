#pragma once
#include "Bar.h"

#define Ball_Radius 10.0f

class Ball : public CircleCollider
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);
	Vector2 _direction = Vector2(1, -2).NormalVector2();

	bool _isUsed = false;
	bool _isActive = false;

private:
	HBRUSH _brush;
	float _speed = 15.0f;
	bool _start = false;
};

