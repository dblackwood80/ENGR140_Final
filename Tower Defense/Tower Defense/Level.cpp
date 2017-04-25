#include "Level.h"
#include <iostream>

Level::Level(Vector2 originalPoints)
{
	this->originalPoints = originalPoints;
	//coord = points.(64)
	//waypoints.
	waypoints.push_back(Vector2(originalPoints.X, originalPoints.Y + (1.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X, originalPoints.Y - (3.0f * tileSize))); 
	waypoints.push_back(Vector2(originalPoints.X + (6.0f * tileSize), originalPoints.Y - (3.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (6.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (4.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (4.0f * tileSize), originalPoints.Y - (8.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (8.0f * tileSize), originalPoints.Y - (8.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (8.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (10.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (10.0f * tileSize), originalPoints.Y - (9.0f * tileSize)));
	//std::cout << waypoints.front().X << ", " << waypoints.front().Y << std::endl;
	//std::cout << waypoints.back().X << ", " << waypoints.back().Y << std::endl;

	std::cout << waypoints.at(0).X << "ghk" << std::endl;
}

Level::~Level()
{
}

std::deque<Vector2> Level::Waypoints()
{
	return waypoints;
}
