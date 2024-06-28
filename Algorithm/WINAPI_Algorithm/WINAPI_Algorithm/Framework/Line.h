#pragma once
class Line
{
public :
	Line(Vector2 start, Vector2 end);
	~Line() {}

	void Update();
	void Render(HDC hdc);

	void SetRed() {_curPen = _pens[0];}
	void SetGreen() {_curPen = _pens[1];}


	void Projection1(shared_ptr<class Line> other);
	void Projection2(shared_ptr<class Line> land, shared_ptr<class Line> other);

	bool IsCollision(shared_ptr<Line>other);
	Vector2 CollisionPoint(shared_ptr<Line>other);

public:
	vector<HPEN> _pens;
	HPEN _curPen;

	Vector2 _start;
	Vector2 _end;

};

