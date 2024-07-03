#pragma once

#include "Border.h"
#include "Brick.h"
#include "Wall.h"

#define BRICK_COUNT_X			10
#define BRICK_COUNT_Y			3

#define WINDOW_OFFSET			(WIN_WIDTH - BRICK_WIDTH * BRICK_COUNT_X) * 0.5f

class Border
{
public:
	Border();
	~Border();

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<class Brick>>> GetBricks() { return _bricks; }
	vector<shared_ptr<class Wall>> GetWalls() { return _walls; }

private:
	vector<vector<shared_ptr<class Brick>>> _bricks;
	vector<shared_ptr<class Wall>> _walls;

	vector<HBRUSH> _brushes;
};

