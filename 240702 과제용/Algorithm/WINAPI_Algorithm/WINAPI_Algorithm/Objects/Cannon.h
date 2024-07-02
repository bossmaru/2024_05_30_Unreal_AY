#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();
	void TakeDamage(float amount);
	float getHp() { return _hp; }

	bool _isActive = true;
	bool _isControled = false;
	bool _turnOver = false;
	int _bulletCount = 0;

	shared_ptr<Collider> GetCollider() { return _body; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

private:

	shared_ptr<Collider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Bullet>> _bullets;

	float _angle = -PI * 0.5f;
	float _hp = 5.0f;
};

