#include "pch.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle1 = make_shared<CircleCollider>(Vector2(500, 500), 50);
	_moveCircle = make_shared<CircleCollider>(Vector2(0, 0), 30);
	_rect1 = make_shared<RectCollider>(Vector2(300, 300), Vector2(50, 80));
	_moveRect = make_shared<RectCollider>(Vector2(150, 150), Vector2(30, 50));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{

	// _moveCircle->_center = mousePos;
	_moveRect->_center = mousePos;

	_circle1->Update();
	_moveCircle->Update();

	_rect1->Update();
	_moveRect->Update();

	// if (_circle1->IsCollision(mousePos))
	// {
	// 	_circle1-> SetRed();
	// }
	// else
	// {
	// 	_circle1->SetGreen();
	// }

	// if (_circle1->IsCollision(_moveCircle))
	// {
	// 	_circle1->SetRed();
	// 	_moveCircle->SetRed();
	// }
	// else
	// {
	// 	_circle1->SetGreen();
	// 	_moveCircle->SetGreen();
	// }

	/*if (_moveCircle->IsCollision(_rect1))
	{
		_rect1->SetRed();
		_moveCircle->SetRed();
	}
	else
	{
		_rect1->SetGreen();
		_moveCircle->SetGreen();
	}*/

	 //if (_rect1->IsCollision(mousePos))
	 //{
	 //	_rect1->SetRed();
	 //}
	 //else
	 //{
	 //	_rect1->SetGreen();
	 //}

	// if (_moveRect->IsCollision(_circle1))
	// {
	// 	_moveRect->SetRed();
	// 	_circle1->SetRed();
	// }
	// else
	// {
	// 	_moveRect->SetGreen();
	// 	_circle1->SetGreen();
	// }

	 if (_moveRect->IsCollision(_rect1))
	 {
	 	_moveRect->SetRed();
	 	_rect1->SetRed();
	 }
	 else
	 {
	 	_moveRect->SetGreen();
	 	_rect1->SetGreen();
	 }
}

void CollisionScene::Render(HDC hdc)
{
	_circle1->Render(hdc);
	_moveCircle->Render(hdc);
	_rect1->Render(hdc);
	_moveRect->Render(hdc);
}
