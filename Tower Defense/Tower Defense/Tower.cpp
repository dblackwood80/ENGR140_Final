#include "Tower.h"
#include "freeglut.h"
#include <iostream>

float width = 0.18f;
float height = 0.18f;

void Tower::init(GLuint texture, Vector2 position, float xx, float yy)
{
	//center = Vector2(position.X + 0.09f, position.Y + 0.09f);
	this->texture = texture;
	this->position.X = position.X;
	this->position.Y = position.Y;
	this->center.X = position.X + 0.09f;
	this->center.Y = position.Y + 0.09f;
	x1 = xx;
	y1 = yy;
	t1 = 55;
	std::cout << "POSITION: " << position.X << ", " << position.Y << std::endl;
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

void Tower::Draw()//std::vector<Tower>& tower, std::deque<Enemy> enemies)
{

	//time = 0;
	/*int timeBullet = glutGet(GLUT_ELAPSED_TIME);

	bulletDelta = timeBullet - oldTime;

					if (bulletDelta > 1000)
					{
						bulletDelta = 0;
						oldTime = timeBullet;
						Bullet bull;
						bull.init(Vector2(center.X - 0.09f + b.bulletVec.size()*0.01f, center.Y - 0.09f), angle, 0.01f, 1, *targets, targets->position);
						//bull.position.X = 0.0f;
						//bull.position += 0.01f;
						b.bulletVec.push_back(bull);

					}
					b.Updates();*/
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glEnable(GL_TEXTURE_2D); // This line and next need to be in loop
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		//std::cout << "STUFF: " << angle << ", " << center.X << ", " << center.Y << std::endl;
		glTranslatef(center.X - 0.09, center.Y - 0.09, 0.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		glTranslatef(-center.X + 0.09, -center.Y + 0.09, 0.0f);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);
		glVertex2f(center.X, center.Y);

		glTexCoord2f(0.0, 1.0);
		glVertex2f(center.X, center.Y - 0.18f);

		glTexCoord2f(1.0, 1.0);
		glVertex2f(center.X - 0.18f, center.Y - 0.18f);

		glTexCoord2f(1.0, 0.0);
		glVertex2f(center.X - 0.18f, center.Y);
		glEnd();

		glPopMatrix();

		//glMatrixMode(GL_MODELVIEW);

		glDisable(GL_TEXTURE_2D);

		glBegin(GL_LINE_LOOP);

		for (int j = 0; j < 360; j++)
		{
			double angle = 3.14159 * 2 / 360;
			double x = center.X + (0.3*sin(angle));
			double y = center.Y + (0.3*cos(angle));
			glVertex2d(x, y);
			//float degInRad = j * (3.14159f / 180.0f);
			//glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
		}

		glEnd();
	//}

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
	return targets;
}

void Tower::GetEnemy(std::deque<Enemy> enemies)
{
	targets = NULL;

	float smallestRange = radius;

	for (int i = 0; i < enemies.size(); i++)
	{
		if (Vector2().Distance(center, enemies.at(i).center) < smallestRange)
		{
			smallestRange = Vector2().Distance(center, enemies.at(i).center);
			*targets = enemies.at(i);
			targets->center.X = targets->position.X + 0.09f;
			targets->center.Y = targets->position.Y + 0.09f;
			std::cout << "CENTERS: " << enemies.at(i).center.X << ", " << targets->center.X << std::endl;
		}
	}
}

void Tower::RotateToTarget()
{
	Vector2 direction;// = center - targets.center;
	
	direction.X = -center.X + targets->center.X;
	direction.Y = -center.Y + targets->center.Y;
	
	float val = 1.0f / (float)sqrt((direction.X * direction.X) + (direction.Y * direction.Y));
	direction.X *= val;
	direction.Y *= val;

	angle = (float)atan2(-direction.X, direction.Y);
	angle = angle * (180.0f / 3.14159f) - 180.0f;
	angle = 0;
	//angle = (float)atan2(-direction.X, direction.Y);
	//angle += 90;
}

void Tower::Updates()
{
	time = glutGet(GLUT_ELAPSED_TIME);

	//delta = time - oldTime;

	if (Target() == NULL)
	{
		std::cout << "VERY NULL" << std::endl;
	}

	//angle = 90;
	if (Target() != NULL)
	{
		std::cout << "rotate" << std::endl;
		RotateToTarget();

		/*if (!IsInRange(enemies.at(0).center))
		{
			delta = 0;
			oldTime = time;
		}*/
	}
}

