#include "WaveManager.h"

WaveManager::WaveManager()
{
}

WaveManager::~WaveManager()
{
}

Wave WaveManager::CurrentWave()
{
	return waves.front();
}

std::deque<Enemy> WaveManager::Enemies()
{
	return CurrentWave().enemies;
}

int WaveManager::Round()
{
	return CurrentWave().RoundOver() + 1;
}

void WaveManager::StartNextWave()
{
	if (waves.size() > 0)
	{
		waves.front().Start();
		std::cout << "WHY: " << CurrentWave().speed << std::endl;
		
		timeSinceLastWave = 0;
		waveDone = false;
	}
}

void WaveManager::DrawAllWaves()
{
	CurrentWave().DrawWaves();
}

void WaveManager::init(Level level, int numberOfWaves, Player player, GLuint enemyTexture)
{
	this->level = level;
	this->numOfWaves = numberOfWaves;
	this->player = player;
	this->enemyTexture = enemyTexture;

	for (int i = 0; i < numberOfWaves; i++)
	{
		int initialNumOfEnemies = 6;
		int numMod = (i / 6) + 1;

		//std::cout << initialNumOfEnemies * numMod << std::endl;

		Wave wave;
		wave.init(i, 5, player, level, enemyTexture);

		waves.push_back(wave);
	}

	StartNextWave();
	
}

void WaveManager::Updates()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	//int delta;

	//delta or timeSinceLastWave = time - oldTimer;

	CurrentWave().Updates();

	if (CurrentWave().RoundOver())
	{
		waveDone = true;
	}

	if (waveDone)
	{
		timeSinceLastWave += glutGet(GLUT_ELAPSED_TIME);
	}

	if (timeSinceLastWave > 30.0f)
	{
		waves.pop_front();
		StartNextWave();
		//timeSinceLastWave = 0;
	}
}
