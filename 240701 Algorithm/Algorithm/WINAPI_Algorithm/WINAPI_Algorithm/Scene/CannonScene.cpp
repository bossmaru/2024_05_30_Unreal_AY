#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"
#include "windows.h"

// 사양서
// 턴제 포트리스
// 각 cannon을 턴마다 서로 컨트롤을 받아서 공격
// cannon의 HP는 5
// 맞으면 hp - 1, hp가 0이면 cannon이 사라짐

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

	_cannon1->_isControled = true;
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();
	for (auto bullet : _cannon1->GetBullets())
	{
		if (bullet->IsActive())
		{
			bullet->Attack_Cannon(_cannon2);
		}
	}
	for (auto bullet : _cannon2->GetBullets())
	{
		if (bullet->IsActive())
		{
			bullet->Attack_Cannon(_cannon1);
		}
	}

	if (_cannon1->_isControled)
	{
		for (auto bullet : _cannon1->GetBullets())
		{
			bullet->Attack_Cannon(_cannon2);
		}
		if (_cannon1->_turnOver)
		{
			_cannon1->_isControled = false;
			_cannon2->_isControled = true;
		}
	}
	else if (_cannon2->_isControled)
	{
		for (auto bullet : _cannon2->GetBullets())
		{
			bullet->Attack_Cannon(_cannon1);
		}
		if (_cannon2->_turnOver)
		{
			_cannon2->_isControled = false;
			_cannon1->_isControled = true;
		}
	}

	// Attack1
	//for (auto bullet : _cannon1->GetBullets())
	//{
	//	bullet->Attack_Cannon(_cannon2);
	//}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}

bool CannonScene::End()
{
	if (!_cannon1->_isActive || !_cannon2->_isActive)
	{
		return true;
	}
	return false;
}
