#include "pch.h"
#include "ArkPlayer.h"
#include "Bar.h"
#include "Ball.h"
#include "Brick.h"
#include "Border.h"

ArkPlayer::ArkPlayer()
{
	_bar = make_shared<Bar>();
	_balls.reserve(BALL_COUNT);
	for (int i = 0; i < BALL_COUNT; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_balls.push_back(ball);
	}

	_curBall = _balls[0];
}

ArkPlayer::~ArkPlayer()
{
}

void ArkPlayer::Update()
{
	_bar->Update();
	if (!_curBall->_start)
	{
		_curBall->_center._x = _bar->_center._x;
	}
	if (!_curBall->_isActive)
	{
		auto iter = std::find_if(_balls.begin(), _balls.end(),
			[](shared_ptr<Ball> ball)->bool
			{
				if (!ball->_isUsed) return true;
				return false;
			});

		if (iter != _balls.end())
		{
			(*iter)->_isActive = true;
			(*iter)->_isUsed = true;
			_curBall = (*iter);
			return;
	
		}
	}
	_curBall->Update();
}

void ArkPlayer::Render(HDC hdc)
{
	_bar->Render(hdc);
	if (_curBall->_isActive)
	{
		_curBall->Render(hdc);
	}
}

void ArkPlayer::BallCollision(shared_ptr<Border> border)
{
	_curBall->BorderCollision(border->GetWalls());
	_curBall->BrickCollision(border->GetBricks());
	_curBall->BarCollision(_bar);
	_curBall->OutofWindow(border->GetWalls());
}
