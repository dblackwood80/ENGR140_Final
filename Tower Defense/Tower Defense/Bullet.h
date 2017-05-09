#ifndef BULLET_H
#define BULLET_H

#include "Vector2.h"
#include "freeglut.h"
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "App.h"

class Bullet
{

public:
	Bullet();
	~Bullet();

	App *a;

	int damage, age;
	float rotation, speed;
	Vector2 position, velocity, center;
	bool IsDead();
	void init(Vector2 position, float rotation, float speed, int damage);//, Enemy enemies, Vector2 enemypos);
	void Kill();
	void Updates();
	void SetRotation(float val);
};

#endif // !BULLET_H
