#include "Tower.h"
#include "freeglut.h"

float width = 0.1f;
float height = 0.1f;

Tower::Tower()
{
	
}

Tower::Tower(float x, float y)
{
	this->x = x;
	this->y = y;
}

Tower::~Tower()
{
}

void Tower::Draw(std::vector<Tower>& tower)
{
	for (int i = 0; i < tower.size(); i++)
	{
		glColor3f(0.0f, 0.0f, 0.0f);

		glBegin(GL_QUADS);

		glVertex2f(tower.at(i).x, tower.at(i).y);
		glVertex2f(tower.at(i).x + width, tower.at(i).y);
		glVertex2f(tower.at(i).x + width, tower.at(i).y - height);
		glVertex2f(tower.at(i).x, tower.at(i).y - height);

		glEnd();
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
