#include "Enemy.h"
#include "freeglut.h"
#include <iostream>

void Enemy::init(GLuint texture, Vector2 position, float health, int bountyGiven, float speed)
{
	this->texture = texture;
	this->position = position;
	this->startHealth = health;
	this->currentHealth = startHealth;
	this->bountyGiven = bountyGiven;
	this->speed = speed;
}

Enemy::Enemy() : Sprite(texture, position)
{
}

Enemy::~Enemy()
{
	
}

GLuint Enemy::loadEnemy(const char* filename)
{
		GLuint texture_id;
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glShadeModel(GL_FLAT);
		glEnable(GL_DEPTH_TEST);

		RgbImage theTexMap(filename);

		// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
		//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


		glGenTextures(1, &texture_id);
		glBindTexture(GL_TEXTURE_2D, texture_id);





		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
			GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

		return texture_id;
}

void Enemy::drawEnemy()
{
	glBindTexture(GL_TEXTURE_2D, texture);
	//std::cout << texture << std::endl;

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glPushMatrix();

	glRotatef(angleFacing, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
	
	glTexCoord2f(0.0, 0.0);
	glVertex2f(position.X, position.Y);	

	glTexCoord2f(0.0, 1.0);
	glVertex2f(position.X, position.Y - tileHeight);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(position.X + tileWidth, position.Y - tileHeight);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(position.X + tileWidth, position.Y);
	glEnd();

	glPopMatrix();

	
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_TEXTURE_2D);
}

void Enemy::SetWaypoints(std::deque<Vector2> waypoints)
{
	/*for each (Vector2 waypoint in waypoints)
	{
		waypoints.push_back(waypoint);
	}*/

	numOfPoints = waypoints.size();

	for (int i = 0; i < numOfPoints; i++)
	{
		//std::cout << waypoints.at(i).X << std::endl;
		points.push_back(Vector2(waypoints.at(i).X, waypoints.at(i).Y));
	}
	
	this->position = points.front();
	points.pop_front();
}

float Enemy::DistanceToDestination()
{
	return Vector2().Distance(position, this->points.front());
}

float Enemy::getHealth()
{
	return currentHealth; 
}

void Enemy::setHealth(float health)
{
	 currentHealth = health;
}

bool Enemy::IsDead()
{
	return !alive;
}

int Enemy::BountyGiven()
{
	return bountyGiven;
}

void Enemy::Updates()
{
	numOfPoints = points.size();

	if (points.size() > 0)
	{
		//std::cout << "1" << std::endl;
		if (DistanceToDestination() < speed)
		{
			//std::cout << "2" << std::endl;
			//std::cout << "Here 1" << std::endl;
			position = points.front();
			points.pop_front();
		}
		else
		{
			
			//std::cout << "Here 2 " << DistanceToDestination() << std::endl;
			Vector2 direction;// = points.front() - position; //Vector2 subtracting vectors was wrong implementation
			direction.X = points.front().X - position.X;
			direction.Y = points.front().Y - position.Y;

			float val = 1.0f / (float)sqrt((direction.X * direction.X) + (direction.Y * direction.Y));
			direction.X *= val;
			direction.Y *= val;

			if (direction.X == 0 && direction.Y == -1) //Face down
			{
				angleFacing = -90.0f;
			}
			else if (direction.X == 0 && direction.Y == 1) //Face up
			{
				angleFacing = 90.0f;
			}
			else if (direction.X == -1 && direction.Y == 0) //Face left
			{
				angleFacing = 180.0f;
			}
			else if (direction.X == 1 && direction.Y == 0) //Face right
			{
				angleFacing = 0.0f;
			}

			//std::cout << direction.X << ", " << direction.Y << std::endl;

			//direction.Normalize();

			//velocity = Vector2().Multiply(direction, speed);
			velocity.X = direction.X * speed;
			velocity.Y = direction.Y * speed;
			//std::cout << position.X << ", " << position.Y << std::endl;
			position.X = position.X + velocity.X;
			ran += 1;
			position.Y = position.Y + velocity.Y;
			//std::cout << position.X << ", " << position.Y << std::endl;
			//std::cout << "3 " << velocity.Y << ", " << position.Y << ", " << ran << std::endl;
		}
	}
	else
	{
		alive = false;
	}
}

std::deque<Vector2> Enemy::Waypoint()
{
	return points;
}

Enemy Enemy::operator=(Enemy value1)
{
	return value1;
}