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
	void SetDirection(Vector2 direction) { _direction = direction; }

private:
	Vector2 _direction = Vector2(1, -1);
	HBRUSH _brush;
	float _speed = 15.0f;
	bool _start = false;
};

