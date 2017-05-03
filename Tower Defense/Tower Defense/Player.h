#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Tower.h"
#include "Level.h"
#include "GlutApp.h"

class Player
{
public:
	Player();
	void init(Level level, GLuint towerTexture);
	~Player();

	int Money();

	int Lives();

	void Draw();

	bool InBounds(float y);

	bool Contains(float x, float y);

	float width = 0.18f, height = 0.18f;

	Tower ContainsTower(float x, float y);

	void Updates(std::deque<Enemy> enemies);

	GlutApp* app;

	int money = 500;
	int lives = 30;

	int cellX, cellY;

	std::vector<Tower> towers;
	Level level;

	GLuint towerTexture;
};

#endif // !PLAYER_H
