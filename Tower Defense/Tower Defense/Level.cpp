#include "Level.h"
#include <iostream>

Level::Level()
{
}

Level::Level(Vector2 originalPoints)
{
	this->originalPoints = originalPoints;

	waypoints.push_back(Vector2(originalPoints.X, originalPoints.Y + (4.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X, originalPoints.Y + (3.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X, originalPoints.Y - (3.0f * tileSize))); 
	waypoints.push_back(Vector2(originalPoints.X + (6.0f * tileSize), originalPoints.Y - (3.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (6.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (4.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (4.0f * tileSize), originalPoints.Y - (8.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (8.0f * tileSize), originalPoints.Y - (8.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (8.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (10.0f * tileSize), originalPoints.Y - (6.0f * tileSize)));
	waypoints.push_back(Vector2(originalPoints.X + (10.0f * tileSize), originalPoints.Y - (9.0f * tileSize)));

	for (int xTile = 1; xTile < 12; xTile++)
	{
		//std::cout << "done 1" << std::endl;
		for (int yTile = 1; yTile < 10; yTile++)
		{
			//std::cout << "done 2" << std::endl;
			if (map[yTile - 1][xTile - 1] == 0) //if grass
			{
				//std::cout << map[yTile - 1][xTile - 1] << ", " << tileWidth * xTile << ", " << tileHeight * yTile << std::endl;
			}
			else if (map[yTile - 1][xTile - 1] == 1) //else if path
			{
				allPathPoints.push_back(Vector2(originalPoints.X + ((xTile - 1) * tileSize), originalPoints.Y - ((yTile - 1) * tileSize)));
				//std::cout << map[yTile - 1][xTile - 1] << ", " << map[yTile - 1][xTile - 1] << std::endl;
				//std::cout << map[yTile - 1][xTile - 1] << ", " << tileWidth * xTile << ", " << tileHeight * yTile << std::endl;
			}
		}
	}

	std::cout << "Points 1 " << allPathPoints.at(0).X  << ", " << allPathPoints.at(0).Y << ", " << allPathPoints.size() << std::endl;
}

Level::~Level()
{
}

std::deque<Vector2> Level::Waypoints()
{
	return waypoints;
}

std::deque<Vector2> Level::AllPathPoints()
{
	return allPathPoints;
}

bool Level::CheckPlacement(float x, float y, std::deque<Vector2> points)
{
	for (int i = 0; i < points.size(); i++)
	{
		//std::cout << "Points 2 " << waypoints.at(i).X << ", " << waypoints.at(i).Y << std::endl;
		if (x >= points.at(i).X && x < points.at(i).X + tileSize)
		{
			//std::cout << "Points 3 " << waypoints.at(i).X << ", " << waypoints.at(i).Y << std::endl;
			if (y > points.at(i).Y - tileSize && y <= points.at(i).Y)
			{
				//std::cout << "Points 4 " << waypoints.at(i).X << ", " << waypoints.at(i).Y << std::endl;
				return true;
			}

		}
	}
	//std::cout << "Points 5 " << waypoints.at(9).X << ", " << waypoints.at(9).Y << std::endl;
	return false;
}

void Level::Draw()
{

}

