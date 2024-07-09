#pragma once

class Maze;
class Block;

class Player
{
public:
	struct Vertex_Dijkstra
	{
		bool operator<(const Vertex_Dijkstra& other) const
		{
			if (g < other.g)
				return true;
			return false;
		}

		bool operator>(const Vertex_Dijkstra& other) const
		{
			if (g > other.g)
				return true;
			return false;
		}

		float g;
		Vector2 pos;
	};

	struct Vertex
	{
		bool operator<(const Vertex& other) const
		{
			if (f < other.f)
				return true;
			return false;
		}

		bool operator>(const Vertex& other) const
		{
			if (f > other.f)
				return true;
			return false;
		}

		float g;
		float h; // -> 맨해튼 거리 함수
		float f; // g + h
		Vector2 pos;
	};

	Player(shared_ptr<Maze> maze);
	~Player();

	void BeginPlay();

	// Find Path 알고리즘
	void RightHand();
	void DFS(Vector2 start);
	void BFS(Vector2 start);
	void DIjkstra(Vector2 start);
	void Astar(Vector2 start, Vector2 end);

	bool Cango(int y, int x);

	void Update();

private:
	Vector2 _pos = {1,1};

	vector<Vector2> _path;
	int _pathIndex = 0;
	float  _time = 0.0f;

	Vector2 _dir = Vector2(0,1);

	shared_ptr<Maze> _maze;

	// DFS
	vector<vector<bool>> _visited;
};

