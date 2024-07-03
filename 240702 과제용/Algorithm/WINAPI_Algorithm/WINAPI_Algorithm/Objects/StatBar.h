#pragma once
class StatBar
{
public:
	StatBar(Vector2 center, Vector2 halfsize, float maxHp, float curHp);	
	~StatBar();

	void Update();
	void Render(HDC hdc);

	shared_ptr<Collider> _hpBar;

private:
	HBRUSH _brush;
};

