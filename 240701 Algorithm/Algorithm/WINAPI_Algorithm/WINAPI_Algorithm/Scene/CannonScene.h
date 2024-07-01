#pragma once

class Cannon;
class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

	void Battle(shared_ptr<Cannon> attacker, shared_ptr<Cannon> defender);
	bool End();


private:
	int _turn = 1;
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;
};

