#ifndef BULLET_H
#define BULLET_H

#include "Vector2.h"
#include "freeglut.h"
#include <vector>
#include <iostream>
#include "Enemy.h"

class Bullet
{

public:
	Bullet();
	~Bullet();

	int damage, age;
	float rotation, speed;
	Vector2 position, velocity, center, enemypos;
	Enemy enemies;
	std::vector<Bullet> bulletVec;
	bool IsDead();
	void init(Vector2 position, float rotation, float speed, int damage, Enemy enemies, Vector2 enemypos);
	void Kill();
	void Updates();
	void SetRotation(float val);

	void Draw();

};

#endif // !BULLET_H
