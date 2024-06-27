#pragma once
class Line
{
public :
	Line(Vector2 start, Vector2 end);
	~Line() {}

	void Update();
	void Render(HDC hdc);

	void contour(shared_ptr<class Line> other);
	void contour2(shared_ptr<class Line> land, shared_ptr<class Line> other);

public:
	Vector2 _start;
	Vector2 _end;

};

