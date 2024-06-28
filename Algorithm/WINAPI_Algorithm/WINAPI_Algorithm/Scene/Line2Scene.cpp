#include "pch.h"
#include "Line2Scene.h"

Line2Scene::Line2Scene()
{
	_line1 = make_shared<Line>(Vector2(50, 50), Vector2(50, 50));
	_line2 = make_shared<Line>(Vector2(50, 600), Vector2(800, 50));

	_circle = make_shared<CircleCollider>(Vector2(300, 300), 5);
}

Line2Scene::~Line2Scene()
{
}

void Line2Scene::Update()
{
	_line1->_end = mousePos;

	_line1->Update();
	_line2->Update();
	_circle->Update();

	if (_line1->IsCollision(_line2))
	{
		_line1->SetRed();
		_line2->SetRed();
		_circle->_center = _line1->CollisionPoint(_line2);
	}
	else
	{
		_line1->SetGreen();
		_line2->SetGreen();
	}
}

void Line2Scene::Render(HDC hcd)
{
	_line1->Render(hcd);
	_line2->Render(hcd);
	_circle->Render(hcd);
}
