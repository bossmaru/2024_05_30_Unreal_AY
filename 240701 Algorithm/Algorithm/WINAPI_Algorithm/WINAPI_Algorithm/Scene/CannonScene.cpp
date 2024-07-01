#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"

// 사양서
// 턴제 포트리스
// 각 cannon을 턴마다 서로 컨트롤을 받아서 공격
// cannon의 HP는 5
// 맞으면 hp - 1, hp가 0이면 cannon이 사라짐

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();

	shared_ptr<Cannon> attacker;
	shared_ptr<Cannon> defender;
	if (!_cannon1->_isControlled && !_cannon2->_isControlled)
	{
		shared_ptr<Cannon> defender;
		if (_turn % 2 == 1)
		{
			attacker = _cannon1;
			defender = _cannon2;
		}
		else
		{
			attacker = _cannon2;
			defender = _cannon1;
		}

		attacker->_isControlled = true;
		defender->_isControlled = false;
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

void CannonScene::Battle(shared_ptr<Cannon> attacker, shared_ptr<Cannon> defender)
{

	for (auto bullet : attacker->GetBullets())
	{
		bullet->SetTarget(defender);
		bullet->Attack_Cannon();
		defender->TakeDamage();
	}

	_turn++;
}

bool CannonScene::End()
{
	if (!_cannon1->_isActive || !_cannon2->_isActive)
	{
		return true;
	}
	return false;
}
