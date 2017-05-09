#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Tower.h"
#include "Level.h"
#include "GlutApp.h"
#include "BulletManager.h"

class Player
{
public:
	Player();
	void init(Level level, GLuint towerTexture);
	~Player();

	int Money();
	
	int Lives();
	//int oldTime = 0, delta, time, bulletDelta;
	void Draw();

	bool InBounds(float y);

	bool Contains(float x, float y);

	float width = 0.18f, height = 0.18f;

	Tower ContainsTower(float x, float y);

	//void Updates(std::deque<Enemy> & enemies);

	bool IsInRange(Vector2 position);

	GlutApp* app;

	int money = 50;
	int lives = 3;

	int cellX, cellY;

	std::deque<Enemy> Ups(std::deque<Enemy> ty);

	std::vector<Tower> towers;
	std::deque<Enemy> enemy;
	Level level;
	//BulletManager manager;

	GLuint towerTexture;
};

#endif // !PLAYER_H
