#ifndef LEVEL_H
#define LEVEL_H
#include <deque>
#include "Vector2.h"

class Level
{
public:
	float coord;
	float tileSize = 0.18f;

	int map[9][11] = { //our map
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1 },
	};

public:
	Level();
	Level(Vector2 originalPoints);
	~Level();

	std::deque<Vector2> Waypoints();
	std::deque<Vector2> AllPathPoints();

	bool CheckPlacement(float x, float y, std::deque<Vector2> points);

	void Draw();

private:
	std::deque<Vector2> waypoints;
	std::deque<Vector2> allPathPoints;
	Vector2 originalPoints;
};

#endif // !LEVEL_H
