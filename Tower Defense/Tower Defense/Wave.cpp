#include "Wave.h"

Wave::Wave()
{
}

Wave::~Wave()
{
}

void Wave::init(int waveNumber, int numOfEnemies, Player player, Level level, GLuint enemyTexture)
{
	this->waveNumber = waveNumber;
	this->numOfEnemies = numOfEnemies;
	this->player = player;
	this->level = level;
	this->enemyTexture = enemyTexture;
}

bool Wave::RoundOver()
{
	return enemies.size() == 0 && enemiesSpawned == numOfEnemies;
}

int Wave::WaveNumber()
{
	return waveNumber;
}

bool Wave::getAtEnd()
{
	return atEnd;
}

/*std::deque<Enemy> Wave::Enemies()
{
	return enemies;
}*/

void Wave::AddEnemy()
{
	Enemy enemy;
	enemy.init(enemyTexture, level.Waypoints().front(), 50, 5, speed);
	enemy.SetWaypoints(level.Waypoints());
	enemy.ID = enemies.size() + 1;
	enemies.push_back(enemy);
	spawnTimer = 0;
	enemiesSpawned++;
	//std::cout << "spawned: " << enemy.ID << ", " << enemies.size() << std::endl;
}

void Wave::Start()
{
	spawning = true;
	//wavesCount++;
}

void Wave::Updates()
{
	//std::cout << "Reached it here 3 " << enemies.size() << ", " << spawning <<std::endl;

	int timeSpeed = glutGet(GLUT_ELAPSED_TIME), time = glutGet(GLUT_ELAPSED_TIME);
	int delta, deltaSpeed;

	delta = time - oldTime;

	deltaSpeed = timeSpeed - oldSpeedTime;

	/*for (int t = 0; t < player.towers.size(); t++)
	{
		for (int j = 0; j < enemies.size(); j++)
		{
			enemies.at(j).center.X = enemies.at(j).position.X + 0.09f;
			enemies.at(j).center.Y = enemies.at(j).position.Y - 0.09f;
		}

		player.towers.at(t).GetEnemy(enemies);
		player.towers.at(t).Updates();
	}*/

	if (player.towers.size() > 0 && player.towers.at(0).targs.size() > 0)
	std::cout << "TRIED " << player.towers.at(0).targs.at(0).currentHealth << std::endl;

	for (int i = 0; i < enemies.size(); i++)
	{
		//enemies = player.
		if (enemies.size() >= 1)
		{
			enemies.at(i).speed = (speed * deltaSpeed) / (20 * enemies.size());
			//std::cout << enemies.size() << std::endl;
			//deltaSpeed = 0;
			oldSpeedTime = timeSpeed;
		}
		else if (enemies.size() < 1)
		{
			enemies.at(i).speed = (speed * deltaSpeed) / (20);
			oldSpeedTime = timeSpeed;
		}
		
		//Enemy enemy = enemies.at(i);
		//enemy.Updates();
		EnemyUpdates();

		if (enemies.size() > 0 && enemies.at(0).ID == 1)
		{
			//enemies.at(i).currentHealth -= 0.1f;
			//std::cout << "CAN TRY HERE " << enemies.at(0).currentHealth << std::endl;
		}

		if (enemies.at(i).currentHealth <= 0)
		{
			enemies.at(i).alive = false;
		}

		if (enemies.at(i).IsDead())
		{
			//std::cout << "Made this 1" << std::endl;
			if (enemies.at(i).currentHealth > 0)
			{
				//std::cout << "Made this 2" << std::endl;
				atEnd = true;
				player.lives -= 1;
				//std::cout << "Made this 3" << std::endl;
			}
			else
			{
				player.money += enemies.at(i).bountyGiven;
				std::cout << player.money << std::endl;
			}
			//std::cout << "SPEED: " << enemies.at(i).velocity.X << ", " << enemies.at(i).velocity.Y << std::endl;
			enemies.erase(enemies.begin() + i);

			i--;
		}
	}

	if (enemiesSpawned == numOfEnemies)
	{
		spawning = false;
	}

	if (wavesCount == 1 && enemies.size() == 0)
	{
		wavesCount++;
	}

	if (spawning)
	{
		//spawnTimer += (float)
		//std::cout << "spawning" << std::endl;

		if (delta > 2000) // every two seconds (2000 milliseconds)
		{
			AddEnemy();
			//counter = 0;
			//std::cout << "here: " << delta << " " << time << " " << oldTime << std::endl;
			//std::cout << "delta: " << delta << std::endl;
			delta = 0;
			oldTime = time;
			
		}
	}
}

void Wave::DrawWaves()
{
	//std::cout << enemies.at(0).velocity.X << ", " << enemies.at(0).velocity.Y << ", " << enemies.at(0).position.X << ", " << enemies.at(0).position.Y << std::endl;

	for (int i = 0; i < enemies.size(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, enemies.at(i).texture);
		//std::cout << texture << std::endl;

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glPushMatrix();

		glRotatef(enemies.at(i).angleFacing, 0.0f, 0.0f, 1.0f);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);
		glVertex2f(enemies.at(i).position.X, enemies.at(i).position.Y);
		//std::cout << "Reached it here 4" << std::endl;
		glTexCoord2f(0.0, 1.0);
		glVertex2f(enemies.at(i).position.X, enemies.at(i).position.Y - enemies.at(i).tileHeight);

		glTexCoord2f(1.0, 1.0);
		glVertex2f(enemies.at(i).position.X + enemies.at(i).tileWidth, enemies.at(i).position.Y - enemies.at(i).tileHeight);

		glTexCoord2f(1.0, 0.0);
		glVertex2f(enemies.at(i).position.X + enemies.at(i).tileWidth, enemies.at(i).position.Y);
		glEnd();

		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);

		glDisable(GL_TEXTURE_2D);
	}
}

void Wave::EnemyUpdates()
{
	//std::cout << "Reached it here 5" << std::endl;
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies.at(i).points.size() > 0)
		{
			//std::cout << "1" << std::endl;
			if (enemies.at(i).DistanceToDestination() < enemies.at(i).speed)
			{
				//std::cout << "2 " << enemies.at(i).points.front().X << ", " << enemies.at(i).position.X << ", " << enemies.at(i).position.Y << ", " << enemies.at(i).Waypoint().front().X << ", " << enemies.at(i).Waypoint().front().Y << std::endl;
				//std::cout << "Here 1" << std::endl;
				enemies.at(i).position = enemies.at(i).points.front();
				enemies.at(i).points.pop_front();
			}
			else
			{

				//std::cout << "Here 2 " << DistanceToDestination() << std::endl;
				// = points.front() - position; //Vector2 subtracting vectors was wrong implementation
				enemies.at(i).direction.X = enemies.at(i).points.front().X - enemies.at(i).position.X;
				enemies.at(i).direction.Y = enemies.at(i).points.front().Y - enemies.at(i).position.Y;

				//std::cout << "what is " << enemies.front().position.X << ", " << enemies.at(i).position.Y << std::endl;

				float val = 1.0f / (float)sqrt((enemies.at(i).direction.X * enemies.at(i).direction.X) + (enemies.at(i).direction.Y * enemies.at(i).direction.Y));
				enemies.at(i).direction.X *= val;
				enemies.at(i).direction.Y *= val;

				if (enemies.at(i).direction.X == 0 && enemies.at(i).direction.Y == -1) //Face down
				{
					enemies.at(i).angleFacing = -90.0f;
				}
				else if (enemies.at(i).direction.X == 0 && enemies.at(i).direction.Y == 1) //Face up
				{
					enemies.at(i).angleFacing = 90.0f;
				}
				else if (enemies.at(i).direction.X == -1 && enemies.at(i).direction.Y == 0) //Face left
				{
					enemies.at(i).angleFacing = 180.0f;
				}
				else if (enemies.at(i).direction.X == 1 && enemies.at(i).direction.Y == 0) //Face right
				{
					enemies.at(i).angleFacing = 0.0f;
				}

				//std::cout << direction.X << ", " << direction.Y << std::endl;

				//direction.Normalize();

				//velocity = Vector2().Multiply(direction, speed);
				
				//enemies.at(i).velocity = enemies.at(i).direction * enemies.at(i).speed;
				enemies.at(i).velocity.X = enemies.at(i).direction.X * enemies.at(i).speed;
				enemies.at(i).velocity.Y = enemies.at(i).direction.Y * enemies.at(i).speed;
				//std::cout << position.X << ", " << position.Y << std::endl;
				enemies.at(i).position.X = enemies.at(i).position.X + enemies.at(i).velocity.X;
				//std::cout << "alive: " << enemies.at(0). << std::endl;
				enemies.at(i).position.Y = enemies.at(i).position.Y + enemies.at(i).velocity.Y;
				//std::cout << enemies.at(i).position.X << ", " << enemies.at(i).position.Y << std::endl;
				//std::cout << "3 " << enemies.at(0).velocity.X << ", " << enemies.at(0).velocity.Y << std::endl;
				//std::cout << "4 " << enemies.at(0).speed << std::endl;
			}
		}
		else
		{
			enemies.at(i).alive = false;
		}
	}
}
