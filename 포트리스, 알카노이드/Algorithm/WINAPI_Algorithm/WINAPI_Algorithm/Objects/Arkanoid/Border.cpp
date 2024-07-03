#include "pch.h"
#include "Border.h"
#include "Brick.h"
#include "Wall.h"

Border::Border()
{
	shared_ptr<Wall> left_wall = make_shared<Wall>();
	shared_ptr<Wall> right_wall = make_shared<Wall>();
	shared_ptr<Wall> ceiling = make_shared<Wall>();
	shared_ptr<Wall> floor = make_shared<Wall>();

	left_wall->Resize(Vector2(WINDOW_OFFSET * 0.5f, WIN_HEIGHT * 0.5f), Vector2(WINDOW_OFFSET * 0.5f, WIN_HEIGHT * 0.5f));
	right_wall->Resize(Vector2(WIN_WIDTH - WINDOW_OFFSET * 0.5f, WIN_HEIGHT * 0.5f), Vector2(WINDOW_OFFSET * 0.5f, WIN_HEIGHT * 0.5f));
	ceiling->Resize(Vector2(WIN_WIDTH * 0.5f, -100.0f), Vector2(WIN_WIDTH * 0.5f, 100.0f));
	floor->Resize(Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT + 100.0f), Vector2(WIN_WIDTH * 0.5f, 100.0f));
	
	_walls.push_back(left_wall);
	_walls.push_back(right_wall);
	_walls.push_back(ceiling);
	_walls.push_back(floor);

	Vector2 offSet = Vector2(WINDOW_OFFSET + BRICK_WIDTH * 0.5f, 100.0f);
	for (int i = 0; i < BRICK_COUNT_Y; i++)
	{
		vector<shared_ptr<Brick>> _bricks_X;
		for (int j = 0; j < BRICK_COUNT_X; j++)
		{
			Vector2 brickOffset = offSet + Vector2(BRICK_WIDTH * j, BRICK_HEIGHT * i);
			shared_ptr<Brick> brick = make_shared<Brick>();
			brick->SetPosition(brickOffset);
			_bricks_X.push_back(brick);
		}
		_bricks.push_back(_bricks_X);
	}

	_brushes.push_back(CreateSolidBrush(PANTON));
	_brushes.push_back(CreateSolidBrush(SKYCOLOR));
}

Border::~Border()
{
	for (auto brush : _brushes)
		DeleteObject(brush);
}

void Border::Update()
{
	for (auto wall : _walls)
	{
		wall->Update();
	}
	for (auto brick_X : _bricks)
	{
		for (auto brick : brick_X)
		{
			brick->Update();
		}
	}
}

void Border::Render(HDC hdc)
{
	for (auto wall : _walls)
	{
		wall->Render(hdc);
	}
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
}
