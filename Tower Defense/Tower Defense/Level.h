#ifndef LEVEL_H
#define LEVEL_H
#include <deque>
#include "Vector2.h"

class Level
{
public:
	float coord;
	float tileSize = 0.18f;

public:
	Level(Vector2 originalPoints);
	~Level();

	std::deque<Vector2> Waypoints();

private:
	std::deque<Vector2> waypoints;
	Vector2 originalPoints;
};

#endif // !LEVEL_H
