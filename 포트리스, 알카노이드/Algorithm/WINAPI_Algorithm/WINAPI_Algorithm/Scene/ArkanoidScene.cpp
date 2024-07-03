#include "pch.h"
#include "ArkanoidScene.h"
#include "Objects/Arkanoid/ArkPlayer.h"
#include "Objects/Arkanoid/Border.h"


#define BALL_COUNT				5

ArkanoidScene::ArkanoidScene()
{
	_player = make_shared<ArkPlayer>();
	_border = make_shared<Border>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_player->Update();
	_border->Update();

	_player->BallCollision(_border);
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
	_border->Render(hdc);
}