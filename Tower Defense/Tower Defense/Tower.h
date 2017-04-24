#ifndef TOWER_H
#define TOWER_H

#include <vector>
#include "Vector2.h"
#include "freeglut.h"
#include "Sprite.h"
#include "Enemy.h"

class Tower : public Sprite
{
public:
	float x, y, radius;

	int cost, damage;

	Enemy targets;

public:



	Tower();
	~Tower();
	Tower(GLuint texture, Vector2 position);

	void Draw(std::vector<Tower>& tower);
	bool Contains(float x, float y, std::vector<Tower>& tower);
	bool InBounds(float y);
	void DeleteTower(float x, float y, std::vector<Tower>& tower);

	int getCost();

	int getDamage();

	float Radius();

	bool IsInRange(Vector2 position);

	Enemy Target();

	void GetEnemy(std::vector<Enemy> enemies);

	void RotateToTarget();

	void Updates();

};


#endif // !TOWER_H
