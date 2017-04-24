#include "Tower.h"
#include "freeglut.h"
#include <iostream>

float width = 0.18f;
float height = 0.18f;

Tower::Tower(GLuint texture, Vector2 position) : Sprite(texture, position)
{
	this->texture = texture;
	this->position.X = position.X;
	this->position.Y = position.Y;
	radius = 1000;
	//std::cout << "made this here " << this->position.X << ", " << position.Y << std::endl;
}

Tower::Tower() : Sprite(texture, position)
{
}

Tower::~Tower()
{
}

void Tower::Draw(std::vector<Tower>& tower)
{
	//glBindTexture(GL_TEXTURE_2D, texture);

	//glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	for (int i = 0; i < tower.size(); i++)
	{
		glEnable(GL_TEXTURE_2D); // This line and next need to be in loop
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glBindTexture(GL_TEXTURE_2D, tower.at(i).texture);

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

		glDisable(GL_TEXTURE_2D);
	}

	//glFlush();
	//glutSwapBuffers();
}

bool Tower::Contains(float x, float y, std::vector<Tower>& tower)
{
	for (int i = 0; i < tower.size(); i++)
	{
		if (x >= tower.at(i).x - width && x < tower.at(i).x + width)
		{
			if (y > tower.at(i).y - height && y <= tower.at(i).y + height)
			{
				return true;
			}

		}
	}
	return false;
}

bool Tower::InBounds(float y) //Make sure not placing in the store area
{
	if (y > -0.8f + height)
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
	}

	return false;
}

Enemy Tower::Target()
{
	return targets;
}

void Tower::GetEnemy(std::vector<Enemy> enemies)
{
	//target = NULL;
	float smallestRange = radius;

	for (int i = 0; i < enemies.size(); i++)
	{
		if (Vector2().Distance(center, enemies.at(i).center))
		{
			smallestRange = Vector2().Distance(center, enemies.at(i).center);
			targets = enemies.at(i);
			std::cout << enemies.at(i).center.X << ", "<< targets.center.X << std::endl;
		}
	}
}

void Tower::RotateToTarget()
{
	Vector2 direction;// = center - targets.center;
	direction.X = center.X - targets.center.X;
	direction.Y = center.Y - targets.center.Y;
	direction.Normalize();

	rotation = (float)atan2(-direction.X, direction.Y);
}

void Tower::Updates()
{
}
