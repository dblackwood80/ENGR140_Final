#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "Wave.h"

class WaveManager
{
private:
	int numOfWaves;
	float timeSinceLastWave;
	std::deque<Wave> waves;
	GLuint enemyTexture;
	bool waveDone = false;
	Level level;
	Player player;

public:
	WaveManager();
	~WaveManager();

	Wave CurrentWave();
	std::deque<Enemy> Enemies();
	int Round();
	void StartNextWave();
	void DrawAllWaves();

	void init(Level level, int numberOfWaves, Player player, GLuint enemyTexture);

	void Updates();

	int oldTimer = 0;

};


#endif // !WAVEMANAGER_H
