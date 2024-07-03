#include "pch.h"
#include "StatBar.h"

StatBar::StatBar(Vector2 center, Vector2 halfsize, float maxHp, float curHp)
{
	float cur_length = halfsize._x * 2 * curHp / maxHp;
	Vector2 cur_center = Vector2(center._x - halfsize._x + cur_length / 2, center._y);
	Vector2 cur_halfsize = Vector2(cur_length / 2, halfsize._y);

	_hpBar = make_shared<RectCollider>(cur_center, cur_halfsize);

	_brush = CreateSolidBrush(RED);
}

StatBar::~StatBar()
{
	DeleteObject(_brush);
}

void StatBar::Update()
{
	_hpBar->Update();
}

void StatBar::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	_hpBar->Render(hdc);
}
