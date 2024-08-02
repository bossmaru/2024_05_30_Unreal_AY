#include "pch.h"
#include "Cannon.h"
#include "Objects/Barrel.h"
#include "Objects/Bullet.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.0f);
	_barrel = make_shared<Barrel>();
	
	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false);	
		_bullets.push_back(bullet);
	}

	Move();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (IsControlled)
	{
		Move();
		Fire();
	}

	_body->Update();
	_barrel->Update();
	for (auto bullet : _bullets)
	{
		bullet->Update();
	}
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto bullet : _bullets)
	{
		bullet->Render(hdc);
	}

}

void Cannon::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->_center._x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_angle += 0.01f;
	}
	
	_barrel->SetAngle(_angle);
	_barrel->SetStart(_body->_center);
	
}

void Cannon::Fire()
{
	// KEY Down (한번만 누른상태)
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		// (auto iter)
		vector<shared_ptr<class Bullet>>::iterator iter = std::find_if(_bullets.begin(), _bullets.end(), [](shared_ptr<Bullet> bullet)->bool {
			return bullet->IsActive() == false;
		});

		if (iter == _bullets.end()) return;
		(*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
	}
}
