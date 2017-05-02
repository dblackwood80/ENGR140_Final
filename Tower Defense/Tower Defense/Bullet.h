#ifndef BULLET_H
#define BULLET_H

#include "Vector2.h"
#include "freeglut.h"
#include <vector>
#include <iostream>

class Bullet
{

public:
	Bullet();
	~Bullet();

	int damage, age;
	float rotation, speed;
	Vector2 position, velocity, center, enemyPosition;
	std::vector<Bullet> bulletVec;
	bool IsDead();
	void init(Vector2 position, float rotation, float speed, int damage, Vector2 enemyPosition);
	void Kill();
	void Updates();
	void SetRotation(float val);

	void Draw();

};

#endif // !BULLET_H
