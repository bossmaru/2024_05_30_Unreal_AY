#pragma once

class Cannon;
class CannonScene : public Scene
{
public :
	CannonScene();
	~CannonScene();

	void Update();
	void Render (HDC hdc);

private:
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;
};

