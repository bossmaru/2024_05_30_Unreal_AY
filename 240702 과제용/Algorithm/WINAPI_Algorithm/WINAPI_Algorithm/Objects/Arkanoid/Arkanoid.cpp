#include "pch.h"
#include "Arkanoid.h"
#include "Bar.h"
#include "Ball.h"
#include "Brick.h"

Arkanoid::Arkanoid()
{
	Vector2 offSet = Vector2(BrickWidth * 0.5, 100.0f);

	_bar = make_shared<Bar>();
	_balls.reserve(BALL_COUNT);
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
	for (int i = 0; i < BALL_COUNT; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_balls.push_back(ball);
	}

	_curBall = _balls[0];
	_curBall->_isActive = true;
	_curBall->_isUsed = true;
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	_bar->Update();

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
	
		}
	}


	if (_curBall->_isActive)
	{
		_curBall->Update();
		WindowCollision();
		OutofWindow();
	}

	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			brick->Update();
		}
	}

	BrickCollision();
	BarCollision();

}

void Arkanoid::Render(HDC hdc)
{
	_bar->Render(hdc);
	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			if (!brick->_shoot)
			{
				brick->Render(hdc);
			}
		}
	}
	if (_curBall->_isActive)
	{
		_curBall->Render(hdc);
	}
}

void Arkanoid::BrickCollision()
{
	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			if (!brick->_shoot)
			{
				if (_curBall->IsCollision(brick))
				{
					float left = brick->_center._x - brick->_halfSize._x;
					float right = brick->_center._x + brick->_halfSize._x;
					float top = brick->_center._y - brick->_halfSize._y;
					float bottom = brick->_center._y + brick->_halfSize._y;

					shared_ptr<Line> top_line = make_shared<Line>(Vector2(left, top), Vector2(right, top));
					shared_ptr<Line> bottom_line = make_shared<Line>(Vector2(left, bottom), Vector2(right, bottom));
					shared_ptr<Line> left_line = make_shared<Line>(Vector2(left, top), Vector2(left, bottom));
					shared_ptr<Line> right_line = make_shared<Line>(Vector2(right, top), Vector2(right, bottom));

					shared_ptr<Line> circle_vertical = make_shared<Line>(Vector2(_curBall->_center._x, _curBall->_center._y - _curBall->_radius), Vector2(_curBall->_center._x, _curBall->_center._y + _curBall->_radius));
					shared_ptr<Line> circle_horizontal = make_shared<Line>(Vector2(_curBall->_center._x - _curBall->_radius, _curBall->_center._y), Vector2(_curBall->_center._x + _curBall->_radius, _curBall->_center._y));

					if (left_line->IsCollision(circle_horizontal).isCollision || right_line->IsCollision(circle_horizontal).isCollision)
					{
						_curBall->_direction._x *= -1;
					}

					else if (top_line->IsCollision(circle_vertical).isCollision || bottom_line->IsCollision(circle_vertical).isCollision)
					{
						_curBall->_direction._y *= -1;
					}
					else
					{
						_curBall->_direction = (_curBall->_center - brick->_center).NormalVector2();
					}

					brick->_shoot = true;
				}
			}
		}
	}
}

void Arkanoid::BarCollision()
{
	float left = _bar->_center._x - _bar->_halfSize._x;
	float right = _bar->_center._x + _bar->_halfSize._x;
	float top = _bar->_center._y - _bar->_halfSize._y;
	shared_ptr<Line> top_line = make_shared<Line>(Vector2(left, top), Vector2(right, top));

	shared_ptr<Line> circle_vertical = make_shared<Line>(Vector2(_curBall->_center._x, _curBall->_center._y - _curBall->_radius), Vector2(_curBall->_center._x, _curBall->_center._y + _curBall->_radius));

	if (top_line->IsCollision(circle_vertical).isCollision)
	{
		_curBall->_direction._y *= -1;
	}
}

void Arkanoid::WindowCollision()
{
	shared_ptr<RectCollider> left_border = make_shared<RectCollider>(Vector2(-100, WIN_HEIGHT * 0.5), Vector2(100, WIN_HEIGHT * 0.5));
	shared_ptr<RectCollider> right_border = make_shared<RectCollider>(Vector2(WIN_WIDTH + 100, WIN_HEIGHT * 0.5), Vector2(100, WIN_HEIGHT * 0.5));
	shared_ptr<RectCollider> top_border = make_shared<RectCollider>(Vector2(WIN_WIDTH * 0.5, -100), Vector2(WIN_WIDTH * 0.5, 100));

	if (_curBall->IsCollision(left_border) || _curBall->IsCollision(right_border))
	{
		_curBall->_direction._x *= -1;
	}
	else if (_curBall->IsCollision(top_border))
	{
		_curBall->_direction._y *= -1;
	}
}

void Arkanoid::OutofWindow()
{
	shared_ptr<RectCollider> bottom_border = make_shared<RectCollider>(Vector2(WIN_WIDTH * 0.5, WIN_HEIGHT + 100), Vector2(WIN_WIDTH * 0.5, 100));

	if (_curBall->IsCollision(bottom_border))
	{
		_curBall->_isActive = false;
	}
}
