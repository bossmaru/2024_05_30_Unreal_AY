#pragma once

#include "Brick.h"

#define BRICK_COUNT_X 10
#define BRICK_COUNT_Y 3
#define BALL_COUNT 3

class Arkanoid
{
public:
	Arkanoid();
	~Arkanoid();

	void Update();
	void Render(HDC hdc);

	void Collision();

private:
	vector<vector<shared_ptr<class Brick>>> _bricks;
	shared_ptr<class Ball> _ball;
	shared_ptr<class Bar> _bar;
};

