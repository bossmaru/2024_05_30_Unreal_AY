#include "pch.h"
#include "Arkanoid.h"
#include "Bar.h"
#include "Ball.h"
#include "Brick.h"

Arkanoid::Arkanoid()
{
	Vector2 offSet = Vector2(BrickWidth * 0.5, 100.0f);

	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();
	for (int i = 0; i < BRICK_COUNT_Y; i++)
	{
		vector<shared_ptr<Brick>> _bricks_X;
		for (int j = 0; j < BRICK_COUNT_X; j++)
		{
			Vector2 brickOffset = offSet + Vector2(BrickWidth * j, BrickHeight * i);
			shared_ptr<Brick> brick = make_shared<Brick>();
			brick->SetPosition(brickOffset);
			_bricks_X.push_back(brick);
		}
		_bricks.push_back(_bricks_X);
	}
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	_bar->Update();
	_ball->Update();
	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			brick->Update();
		}
	}
	Collision();

}

void Arkanoid::Render(HDC hdc)
{
	_bar->Render(hdc);
	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			brick->Render(hdc);
		}
	}
	_ball->Render(hdc);
}

void Arkanoid::Collision()
{
	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			if (_ball->IsCollision(brick))
			{
				float left = brick->_center._x - brick->_halfSize._x;
				float right = brick->_center._x + brick->_halfSize._x;
				float top = brick->_center._y - brick->_halfSize._y;
				float bottom = brick->_center._y + brick->_halfSize._y;

				if (_ball->_center._x + _ball->_radius > left || _ball->_center._x - _ball->_radius < right)
				{
					_ball->SetDirection(Vector2(_ball->_center._x, -_ball->_center._y));
				}
				else if (_ball->_center._y + _ball->_radius > top || _ball->_center._y - _ball->_radius < bottom)
				{
					_ball->SetDirection(Vector2(-_ball->_center._x, _ball->_center._y));
				}

				brick_X.erase(find(brick_X.begin(), brick_X.end(), brick));
			}
		}
	}
}
