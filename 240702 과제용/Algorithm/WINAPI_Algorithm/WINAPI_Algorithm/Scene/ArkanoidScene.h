#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;	

private:
	shared_ptr<class ArkPlayer> _player;
	shared_ptr<class Border> _border;
};

