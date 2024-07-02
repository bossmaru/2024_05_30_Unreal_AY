#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;	



private:
	shared_ptr<class Arkanoid> _arkanoid;
};

