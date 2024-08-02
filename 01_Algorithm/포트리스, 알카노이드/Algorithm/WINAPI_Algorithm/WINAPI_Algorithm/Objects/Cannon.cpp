#include "pch.h"
#include "Cannon.h"
#include "Objects/Barrel.h"
#include "Objects/Bullet.h"
#include "Objects/StatBar.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.0f);
	_signTurn = make_shared<CircleCollider>(_body->_center, 30.0f);
	_barrel = make_shared<Barrel>();

	for(int i=0;i<3;i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false);
		_bullets.push_back(bullet);
	}

	_maxHpBar = make_shared<RectCollider>(Vector2(_body->_center._x, _body->_center._y - 65.0f), Vector2(50.0f, 5.0f));
	_curHpBar = make_shared<StatBar>(_maxHpBar->_center, Vector2(50.0f, 5.0f), _maxHp, _maxHp);

	Move();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_signTurn->_center = _body->_center;
	_maxHpBar = make_shared<RectCollider>(Vector2(_body->_center._x, _body->_center._y + 65.0f), Vector2(50.0f, 5.0f));
	_maxHpBar->Update();
	_curHpBar = make_shared<StatBar>(_maxHpBar->_center, Vector2(50.0f, 5.0f), _maxHp, _curHp);
	_curHpBar->Update();

	_turnOver = false;
	if (_isControled)
	{
		Move();
		Fire();
	}

	if (_isActive == false) return;

	_body->Update();
	_signTurn->Update();
	_barrel->SetAngle(_angle);
	_barrel->SetStart(_body->_center);
	_barrel->Update();


	for(auto bullet : _bullets)
		bullet->Update();
}

void Cannon::Render(HDC hdc)
{
	if (_isActive == false) return;

	_barrel->Render(hdc);
	_body->Render(hdc);

	if (_isControled)
		_signTurn->Render(hdc);

	for(auto bullet : _bullets)
		bullet->Render(hdc);

	_maxHpBar->Render(hdc);
	_curHpBar->Render(hdc);
}

void Cannon::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->_center._x += 1.0f;
		_signTurn->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->_center._x -= 1.0f;
		_signTurn->_center._x -= 1.0f;
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
	if (_bulletCount == _bullets.size())
	{
		_bulletCount = 0;
		_turnOver = true;
		return;
	}

	// KEY DOWN
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		auto iter = std::find_if(_bullets.begin(), _bullets.end(), 
		[](shared_ptr<Bullet> bullet)->bool 
		{
			if(!bullet->IsActive()) return true;
			return false;
		});

		if (iter != _bullets.end())
		{
			(*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
			_bulletCount++;
		}
	}

}

void Cannon::TakeDamage(float amount)
{
	_curHp -= amount;
	if (_curHp <= 0)
	{
		_curHp = 0;
		_isActive = false;
	}
}
