#include "Tower.h"
#include "freeglut.h"
#include <iostream>

float width = 0.18f;
float height = 0.18f;

void Tower::init(GLuint texture, Vector2 position)
{
	//center = Vector2(position.X + 0.09f, position.Y + 0.09f);
	this->texture = texture;
	this->position.X = position.X;
	this->position.Y = position.Y;
	this->center.X = position.X + 0.09f;
	this->center.Y = position.Y + 0.09f;
	//std::cout << "POSITION: " << position.X << ", " << position.Y << std::endl;
	radius = 0.35f;
	upgradeLevel = 0;
	//angle += 90;
	//std::cout << "made this here " << this->position.X << ", " << position.Y << std::endl;
}

Tower::Tower()
{
}

Tower::~Tower()
{
}

void Tower::Draw(std::vector<Tower>& tower, std::deque<Enemy> enemies)
{
	//glBindTexture(GL_TEXTURE_2D, texture);
	//time = 0;
	int timeBullet = glutGet(GLUT_ELAPSED_TIME);

	bulletDelta = timeBullet - oldTime;
	//glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//std::cout << "MY ANGLE: " << angle << std::endl;
	
	for (int i = 0; i < tower.size(); i++)
	{
		//std::cout << enemies.at(0).position.X << std::endl;
		for (int j = 0; j < enemies.size(); j++)
		{
			//std::cout << "DISTANCE: " << Vector2().Distance(tower.at(i).center, targets.center) << ", " << tower.at(i).radius << ", " << targets.center.X << ", " << targets.center.Y << std::endl;

			enemies.at(j).center.X = enemies.at(j).position.X + 0.09f;
			enemies.at(j).center.Y = enemies.at(j).position.Y + 0.09f;

			if (Vector2().Distance(tower.at(i).center, enemies.at(j).center) < tower.at(i).radius)
			{
				if (j > 0 && (Vector2().Distance(tower.at(i).center, enemies.at(j - 1).center) > tower.at(i).radius))//(tower.at(i).targets.IsDead() || ))
				{
					std::cout << "STAY ON" << std::endl;
				}
				//std::cout << center.X << ", " << tower.at(0).center.X << std::endl;
				Vector2 direction;// = center - targets.center;

				direction.X = -tower.at(i).center.X + enemies.at(j).center.X;
				direction.Y = -tower.at(i).center.Y + enemies.at(j).center.Y;
				//tower.at(0).position = enemies.at(i).position;
				//float val = 1.0f / (float)sqrt((direction.X * direction.X) + (direction.Y * direction.Y));
				//direction.X *= val;
				//direction.Y *= val;
				//std::cout << enemies.at(j).center.X << ", " << enemies.at(j).center.Y << std::endl;
				tower.at(i).angle = (float)atan2(-direction.X, direction.Y);
				tower.at(i).angle = tower.at(i).angle * (180.0f / 3.14159f) - 180.0f;
				//std::cout << "ANGLE: " << tower.at(i).angle << ", " << targets.center.X << std::endl;

				//bullet = tower.at(i).center;
				//bulletVelocity = Vector2().Transform(Vector2(0, -6), Matrix().CreateRotationZ(tower.at(i).angle));
				//bullet += bulletVelocity;
				//bullet.Y += 0.1f;

				if (bulletDelta > 1000)
				{
					bulletDelta = 0;
					oldTime = timeBullet;
					Bullet bull;
					bull.init(Vector2(tower.at(i).center.X - 0.09f + b.bulletVec.size()*0.01f, tower.at(i).center.Y - 0.09f), tower.at(i).angle, 0.01f, 1, enemies.at(j), enemies.at(j).position);
					//bull.position.X = 0.0f;
					//bull.position += 0.01f;
					b.bulletVec.push_back(bull);
					

					std::cout << "BULLETS: " << b.bulletVec.size() << ", " << b.bulletVec.at(0).age << std::endl;

				}
					b.Updates();
				/*for (int a = 0; a < b.bulletVec.size(); a++)
				{

				}*/
				
				/*for (int k = 0; k < tower.size(); k++)
				{
					if (/*delta > 750 && Vector2().Distance(tower.at(k).center, bullet) <= tower.at(k).radius)
					{

						std::cout << "DELTA: " << delta << std::endl;
						glPointSize(10);
						glBegin(GL_POINTS);

						glVertex2f(bullet.X, bullet.Y);

						glEnd();

						delta = 0;
						oldTime = time;
					}*/
				//}

			}
		}

		if (enemies.size() == 0)
		{
			std::cout << "TRUE COUNT: " << b.bulletVec.size() << std::endl;
			b.bulletVec.clear();
		}
		
		glBindTexture(GL_TEXTURE_2D, tower.at(i).texture);

		glEnable(GL_TEXTURE_2D); // This line and next need to be in loop
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();

		glTranslatef(tower.at(i).center.X - 0.09, tower.at(i).center.Y - 0.09, 0.0f);
		glRotatef(tower.at(i).angle, 0.0f, 0.0f, 1.0f);
		glTranslatef(-tower.at(i).center.X + 0.09, -tower.at(i).center.Y + 0.09, 0.0f);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);
		glVertex2f(tower.at(i).center.X, tower.at(i).center.Y);

		glTexCoord2f(0.0, 1.0);
		glVertex2f(tower.at(i).center.X, tower.at(i).center.Y - 0.18f);

		glTexCoord2f(1.0, 1.0);
		glVertex2f(tower.at(i).center.X - 0.18f, tower.at(i).center.Y - 0.18f);

		glTexCoord2f(1.0, 0.0);
		glVertex2f(tower.at(i).center.X - 0.18f, tower.at(i).center.Y);
		glEnd();

		glPopMatrix();

		//glMatrixMode(GL_MODELVIEW);

		glDisable(GL_TEXTURE_2D);

		glBegin(GL_LINE_LOOP);

		for (int j = 0; j < 360; j++)
		{
			double angle = 3.14159 * 2 / 360;
			double x = tower.at(i).center.X + (0.3*sin(angle));
			double y = tower.at(i).center.Y + (0.3*cos(angle));
			glVertex2d(x, y);
			//float degInRad = j * (3.14159f / 180.0f);
			//glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
		}

		glEnd();
	}

	//glFlush();
	//glutSwapBuffers();
}

bool Tower::Contains(float x, float y, std::vector<Tower>& tower)
{
	for (int i = 0; i < tower.size(); i++)
	{
		if (x >= tower.at(i).position.X - (width / 2) && x < tower.at(i).position.X + (width / 2))
		{
			if (y > tower.at(i).position.Y - (height / 2) && y <= tower.at(i).position.Y + (height / 2))
			{
				return true;
			}

		}
	}
	return false;
}

Tower Tower::ContainsTower(float x, float y, std::vector<Tower>& tower)
{
	for (int i = 0; i < tower.size(); i++)
	{
		if (x >= tower.at(i).position.X - (width / 2) && x < tower.at(i).position.X + (width / 2))
		{
			if (y > tower.at(i).position.Y - (height / 2) && y <= tower.at(i).position.Y + (height / 2))
			{
				return tower.at(i);
			}

		}
	}
}

bool Tower::InBounds(float y) //Make sure not placing in the store area
{
	if (y > -0.62f + height)
	{
		return true;
	}
	
	return false;
}

void Tower::DeleteTower(float x, float y, std::vector<Tower>& tower)
{
	for (int i = 0; i < tower.size(); i++)
	{
		if (x >= tower.at(i).x && x < tower.at(i).x + width && y > tower.at(i).y - height && y <= tower.at(i).y)
		{
			tower.erase(tower.begin() + i);
			break;
		}
	}
}

int Tower::getCost()
{
	return cost;
}

int Tower::getDamage()
{
	return damage;
}

float Tower::Radius()
{
	return radius;
}

bool Tower::IsInRange(Vector2 position)
{
	if (Vector2().Distance(center, position) <= radius)
	{
		return true;
		std::cout << "IN RANGE" << std::endl;
	}
	//std::cout << "NOT IN RANGE" << std::endl;
	return false;
}

Enemy *Tower::Target()
{
	return &targets;
}

void Tower::GetEnemy(std::deque<Enemy> enemies, std::vector<Tower> towers)
{
	//std::cout << towers.at(0).center.X << std::endl;
	//targets = NULL;
	float smallestRange = radius;

	for (int i = 0; i < enemies.size(); i++)
	{
		for (int j = 0; j < towers.size(); j++)
		{

			if (Vector2().Distance(towers.at(j).center, enemies.at(i).center) < smallestRange)
			{
				smallestRange = Vector2().Distance(center, enemies.at(i).center);
				targets = enemies.at(i);
				std::cout << "CENTERS: " << enemies.at(i).center.X << ", " << targets.center.X << std::endl;
			}
		}
	}
}

void Tower::RotateToTarget()
{
	Vector2 direction;// = center - targets.center;
	
	direction.X = center.X - targets.center.X;
	direction.Y = center.Y - targets.center.Y;
	
	float val = 1.0f / (float)sqrt((direction.X * direction.X) + (direction.Y * direction.Y));
	direction.X *= val;
	direction.Y *= val;

	//angle = (float)atan2(-direction.X, direction.Y);
	angle += 90;
}

void Tower::Updates(std::deque<Enemy> enemies)
{
	time = glutGet(GLUT_ELAPSED_TIME);

	//delta = time - oldTime;

	//angle = 90;
	if (Target() != NULL)
	{
		//std::cout << "rotate" << std::endl;
		RotateToTarget();

		/*if (!IsInRange(enemies.at(0).center))
		{
			delta = 0;
			oldTime = time;
		}*/
	}
}

