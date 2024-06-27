#include "pch.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _rect = make_shared<RectCollider>(Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f));
    _circle = make_shared<CircleCollider>(Vector2(250.0f, 250.0f), 50.0f);
    _line = make_shared<Line>(Vector2(100.0f, 100.0f), Vector2(200.0f, 200.0f));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
   //  _rect->_center = LERP(_rect->_center, mousePos, 0.1f);
    _rect->Update();

     // 선형보간
    _circle->_center = LERP(_circle->_center, mousePos, 0.1f);
    _circle->Update();
    _line->Update();
}

void PaintScene::Render(HDC hdc)
{
    _rect->Render(hdc);
    _circle->Render(hdc);
    // _line->Render(hdc);
}
