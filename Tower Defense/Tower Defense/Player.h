#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
//#include "Tower.h"
#include "Level.h"
#include "GlutApp.h"

class Player
{
public:
	Player();
	void init(Level level, GLuint towerTexture);
	~Player();



	void mouseMove(float x, float y);
	float mouseX, mouseY;

	int Money();

	int Lives();

	float ConvertX(float & x);

	float ConvertY(float & y);

	bool ValidSpot();

	void Updates();

	GlutApp* app;

	int money = 500;
	int lives = 30;

	int cellX, cellY;

	//std::vector<Tower> towers;
	Level level;

	GLuint towerTexture;
};

#endif // !PLAYER_H
