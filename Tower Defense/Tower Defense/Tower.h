#ifndef TOWER_H
#define TOWER_H

#include <vector>
#include <algorithm>
//#include "freeglut.h"
#include "Vector2.h"
#include "Bullet.h"
//#include "Sprite.h"
//#include "Enemy.h"

class Tower
{
public:
	float x, y, radius, rangeRadius;

	int cost, damage;

	float width = 0.18f, height = 0.18f;

	int upgradeLevel;

	int oldTime = 0, delta, time, bulletDelta;

	GLuint texture;
	Vector2 position, center;
	
	std::vector<Bullet> bulletList;

	/*Vector2 velocity = Vector2(0.0f, 0.0f); //Zero

	Vector2 center;
	Vector2 origin = Vector2(0.09f, 0.09f);

	GLuint texture;

	Vector2 position;
	//Vector2 velocity;

	//Vector2 center;
	//Vector2 origin;

	float rotation;*/

	//std::vector<Enemy> targets;
	
	//Enemy *targets;

	float angle = 0;

	//Vector2 bullet, bulletVelocity;

	//Bullet b;

	std::deque<Enemy> targs;

public:



	Tower();
	~Tower();
	//Tower(GLuint texture, Vector2 posi);

	void init(GLuint texture, Vector2 position);
	void Draw();//std::vector<Tower>& tower, std::deque<Enemy> enemies);
	bool Contains(float x, float y, std::vector<Tower>& tower);
	Tower ContainsTower(float x, float y, std::vector<Tower>& tower);
	bool InBounds(float y);
	void DeleteTower(float x, float y, std::vector<Tower>& tower);

	int getCost();

	int getDamage();

	float Radius();

	float x1, y1, t1;

	bool IsInRange(Vector2 position);

	//Enemy *Target();

	void GetEnemy(std::deque<Enemy> &enemies);

	std::deque<Enemy> TowerUps(std::deque<Enemy> towery);

	void RotateToTarget();

	void Updates(std::deque<Enemy> &enemies);

	std::deque<Enemy> copy;

	std::deque<Enemy> GetCopy();

	bool valueSwaped;
	int index, offset;
};


#endif // !TOWER_H