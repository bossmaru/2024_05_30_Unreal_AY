#pragma once

#include "Brick.h"

#define BALL_COUNT				5

class ArkPlayer
{
public:
	ArkPlayer();
	~ArkPlayer();

	void Update();
	void Render(HDC hdc);

	void BallCollision(shared_ptr<class Border> border);

private:
	vector<shared_ptr<class Ball>> _balls;
	shared_ptr<class Ball> _curBall;
	shared_ptr<class Bar> _bar;
};

