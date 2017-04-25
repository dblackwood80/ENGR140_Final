#ifndef ENEMY_H
#define ENEMY_H

//#include "GlutApp.h"
#include "RgbImage.h"
#include "TexRect.hpp"
#include "Vector2.h"
#include "Sprite.h"

class Enemy : public Sprite
{
private:
	float angleFacing;

public:
	
	Enemy();
	~Enemy();

	GLuint loadEnemy(const char* filename);
	void drawEnemy();
	void SetWaypoints(std::deque<Vector2> waypoints);
	void init(GLuint texture, Vector2 position, float health, int bountyGiven, float speed);
	float DistanceToDestination();

	float getHealth();

	void setHealth(float health);

	bool IsDead();

	int BountyGiven();

	void Updates();

	Enemy operator=(Enemy value1);

	std::deque<Vector2> points;

public:
	//float x, y;
	const float textureWidth = 64, textureHeight = 64;
	float tileWidth = 0.18f, tileHeight = 0.18f;

	float startHealth, currentHealth;
	bool alive = true;
	float speed = 0.5f;
	int bountyGiven;

	int numOfPoints;
};

#endif // !ENEMY_H
