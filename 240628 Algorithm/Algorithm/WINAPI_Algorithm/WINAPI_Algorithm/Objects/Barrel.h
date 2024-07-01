#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetStart(Vector2 start);
	void SetAngle(float angle);

	Vector2 GetEndPos();
	Vector2 GetDirection();

private:
	shared_ptr<Line> _line;
	float _barrelLength = 100.0f;
	Vector2 _direction = Vector2(1, 0);
};

