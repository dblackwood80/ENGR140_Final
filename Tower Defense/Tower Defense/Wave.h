#ifndef WAVE_H
#define WAVE_H

#include "Level.h"
#include "Enemy.h"
#include "Player.h"
#include "freeglut.h"
#include <iostream>
#include <deque>

class Wave
{
private:
	int numOfEnemies;
	int waveNumber;
	int enemiesSpawned = 0;
	double spawnTimer = 0;
	double counter;
	int count = 1;

	bool atEnd;
	bool spawning;

	Level level;

	GLuint enemyTexture;
	std::deque<Enemy> enemies;

	float angleFacing;

public:
	Wave();
	~Wave();
	void init(int waveNumber, int numOfEnemies, Player player, Level level, GLuint enemyTexture);

	bool RoundOver();
	int WaveNumber();
	bool getAtEnd();

	std::deque<Enemy> Enemies();

	int run2 = 0;

	void AddEnemy();
	void Start();
	void Updates();

	void DrawWaves();

	void EnemyUpdates();

	Player player;

	int oldSpeedTime = 0, oldTime = 0;

	//std::vector<Vector2> points;

	//bool alive = true;
	float speed = 0.005f;
};
#endif