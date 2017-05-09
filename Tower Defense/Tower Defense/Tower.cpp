#include "Tower.h"
#include "freeglut.h"
#include <iostream>

float width = 0.18f;
float height = 0.18f;

void Tower::init(GLuint texture, Vector2 position)
{
	//center = Vector2(position.X + 0.09f, position.Y + 0.09f);
	this->texture = texture;
	//this->position.X = position.X;
	//this->position.Y = position.Y;
	this->position = position;
	this->center.X = position.X + 0.09f;
	this->center.Y = position.Y - 0.09f;

	radius = 0.35f;
	rangeRadius = radius + 0.1f;
	upgradeLevel = 0;
	damage = 12;
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
	//std::cout << "TRYS VEL: " << trys.velocity.X << std::endl;

		glBindTexture(GL_TEXTURE_2D, texture);

		glEnable(GL_TEXTURE_2D); // This line and next need to be in loop
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		//std::cout << "STUFF: " << angle << ", " << center.X << ", " << center.Y << std::endl;
		glTranslatef(center.X - 0.09, center.Y + 0.09, 0.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		glTranslatef(-center.X + 0.09, -center.Y - 0.09, 0.0f);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);
		glVertex2f(center.X, center.Y);

		glTexCoord2f(0.0, 1.0);
		glVertex2f(center.X, center.Y + 0.18f);

		glTexCoord2f(1.0, 1.0);
		glVertex2f(center.X - 0.18f, center.Y + 0.18f);

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
			double y = center.Y - (0.3*cos(angle));
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
	if (Vector2().Distance(center, position) < radius)
	{
		return true;
		std::cout << "IN RANGE" << std::endl;
	}
	//std::cout << "NOT IN RANGE" << std::endl;
	return false;
}

/*Enemy *Tower::Target()
{
	return targets;
}*/

void Tower::GetEnemy(std::deque<Enemy> &enemies)
{
	valueSwaped = false;

	//targets = NULL;
	//targs.clear();

	/*if (enemies.size() >= 2)
	{
		//for (int u = 0; u < copy.size(); u++)
		//{
			for (int es = 0; enemies.size(); es++)
			{
				for (int u = 0; u < copy.size(); u++)
				{
					if (enemies.at(es).ID != copy.at(u).ID)
					{
						copy.push_back(enemies.at(es));
						std::cout << "5" << std::endl;
						valueSwaped = true;
						break;
					}
				}

				if (valueSwaped)
					break;
			}
		//}
	}
	else if (enemies.size() == 1)
	{
		//copy.at(0) = enemies.at(0);
		copy.push_back(enemies.at(0));
		std::cout << "5" << std::endl;
	}*/

	if (copy.size() == 0 && enemies.size() == 1)
	{
		copy.push_back(enemies.at(0));
	}

	

	if (enemies.size() > 1 && copy.size() > 0 && copy.size() < 5)
	{
		if (copy.at(copy.size() - 1).ID != enemies.at(enemies.size() - 1).ID)
		{
			copy.push_back(enemies.at(enemies.size() - 1));
		}
	}
	
	valueSwaped = false;

	if (copy.size() == 5)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			for (int c = 0; c < copy.size(); c++)
			{
				if (copy.at(c).ID == enemies.at(e).ID && copy.at(c).currentHealth < enemies.at(e).currentHealth)
				{
					//copy.at(0).currentHealth -= 0.1f;
					enemies.at(e).currentHealth = copy.at(c).currentHealth;
					std::cout << e << " ACTUAL HEALTH: " << enemies.at(e).currentHealth << std::endl;
					valueSwaped = true;
					index = c;
					break;
				}
			}

			if (valueSwaped)
			{
				//std::cout << index << ", " << e << " HEALTH: " << enemies.at(e).currentHealth << ", " << copy.at(index).currentHealth << std::endl;
				valueSwaped = false;
				break;
			}
		}
	}

	targs.clear();

	//std::cout << "CALLED: " << Vector2().Distance(center, enemies.at(0).center) << ", " << radius << ", " << center.X << ", " << center.Y << std::endl;
	float smallestRange = radius;
	//std::cout << "SIZES: " << enemies.size() << std::endl;
	for (int i = 0; i < enemies.size(); i++)
	{
		

		//std::cout << "DIST: " << enemies.at(i).center.X << ", " << enemies.at(i).center.Y << ", " << enemies.at(i).position.X << ", " << enemies.at(i).position.Y << std::endl;
		if (Vector2().Distance(center, enemies.at(i).center) < smallestRange)
		{
			smallestRange = Vector2().Distance(center, enemies.at(i).center);
			//*targets = enemies.at(i);
			targs.push_back(enemies.at(i));
			//std::cout << "IN GET" << std::endl;
			//std::cout << "POSITION: " << targets->position.X << ", " << targets->position.Y << " ," << enemies.at(i).position.X << ", " << enemies.at(i).position.Y << std::endl;
			//std::cout << "CENTERS: " << i << ", " << enemies.at(i).center.X << ", " << trys.velocity.X << std::endl;
		}
		//std::cout << "TARGS SIZE: " << targs.size() << ", " << enemies.at(i).ID << std::endl;
		if (targs.size() > 0)
		{
			//std::cout << "st " << Vector2().Distance(center, targs.at(0).center) << std::endl;
		}
		
		if (targs.size() > 0 && Vector2().Distance(center, targs.at(0).center) >= radius)
		{
			std::cout << "WHY: " << i << std::endl;
			targs.clear();
		}
	}
}

std::deque<Enemy> Tower::TowerUps(std::deque<Enemy> towery)
{
	return towery;
}

void Tower::RotateToTarget()
{
	Vector2 direction;// = center - targets.center;
	for (int i = 0; i < targs.size(); i++)
	{
		direction.X = -center.X + targs.at(0).center.X;
		direction.Y = -center.Y + targs.at(0).center.Y;


		float val = 1.0f / (float)sqrt((direction.X * direction.X) + (direction.Y * direction.Y));
		direction.X *= val;
		direction.Y *= val;

		angle = (float)atan2(-direction.X, direction.Y);
		angle = angle * (180.0f / 3.14159f);
	}
	//angle = 0;
	//angle += 1;
	//angle = (float)atan2(-direction.X, direction.Y);
	//angle += 90;
}

void Tower::Updates(std::deque<Enemy> &enemies)
{
	time = glutGet(GLUT_ELAPSED_TIME);	
	
	int timeBullet = glutGet(GLUT_ELAPSED_TIME);
	bulletDelta = timeBullet - oldTime;

	//delta = time - oldTime;

	//std::cout << angle << std::endl;

	if (targs.size() > 0)
	{
		RotateToTarget();

		for (int i = 0; i < targs.size(); i++)
		{

//			std::cout << "Range: " << Vector2().Distance(center, targs.at(i).center) << " >= " << radius << std::endl;

			if (Vector2().Distance(center, targs.at(i).center) >= radius || targs.at(i).IsDead())
			{
				//std::cout << "not range" << std::endl;
				if (i > 0)
				{
					targs.erase(targs.begin() + i);
					i--;
					bulletDelta = 0;
				}
				else if (i == 0)
				{
					targs.clear();
					bulletDelta = 0;
				}
				delta = 0;
				oldTime = time;
			}
		}

		if (bulletDelta >= 750)
		{
			//std::cout << bulletDelta << " shoot " << targs.size() << std::endl;
			Bullet bull;
			if ((angle > 120 && angle < 180) || (angle > -240 && angle < -180))
			{
				offset = -160;
			}
			else
			{
				offset = 60;
			}
			bull.init(Vector2(center.X-0.09, center.Y+0.09), angle / (180.0f / 3.14159f) - offset, 0.2f, damage);
			//std::cout << "ANGLE: " << angle << std::endl;
			bull.center.X = bull.position.X + 0.03f;
			bull.center.Y = bull.position.Y - 0.03f;
			bulletList.push_back(bull);
			bulletDelta = 0;
			oldTime = time;
		}
	}
	//std::cout << "BULLDELTA: " << bulletDelta << ", " << targs.size() << std::endl;
	

	for (int b = 0; b < bulletList.size(); b++)
	{
		bulletList.at(b).SetRotation(bulletList.at(b).rotation);
		bulletList.at(b).Updates();

		//std::cout << "Range: " << Vector2().Distance(center, bulletList.at(b).center) << " >= " << radius << std::endl;

		if (Vector2().Distance(center, bulletList.at(b).center) >= radius)
		{
			bulletList.at(b).Kill();
			//std::cout << "kill" << std::endl;
		}
		for (int t = 0; t < targs.size(); t++)
		{

			if (Vector2().Distance(bulletList.at(b).center, targs.at(t).center) <= 0.3f)
			{
				//std::cout << targs.at(t).currentHealth << std::endl;
				targs.at(t).currentHealth -= bulletList.at(b).damage;

				//if (copy.size() > 0 && copy.at(targs.at(t).ID - 1))
				//{

				//}

				//std::cout << "HIT " << copy.size() << std::endl;
				for (int cc = 0; cc < copy.size(); cc++)
				{
					//std::cout << "IN" << std::endl;
					if (targs.at(t).ID == copy.at(cc).ID)
					{
						copy.at(cc).currentHealth -= bulletList.at(b).damage;
						std::cout << enemies.at(t).currentHealth << " stuff:" << copy.at(cc).currentHealth << std::endl;
					}
				}

/*				for (int id = 0; id < targs.size(); id++)
				{

					if (id == targs.at(t).ID - 1) 
					{
						copy.at(id).currentHealth -= 55.0f;

						if (copy.at(id).currentHealth <= 0)
						{
							copy.at(id).alive = false;
							//std::cout << "DEAD" << std::endl;
						}
						//if (copy.at(id).ID == 1)
						//std::cout << id << " kill 2 " << copy.at(id).currentHealth << std::endl;
					}
				}*/
				
				//TowerUps(targs);
				//targs.at(t).alive = false;
				bulletList.at(b).Kill();
//				std::cout << "kill 2 " << copy.at(0).currentHealth << std::endl;
			}
		}

		if (bulletList.at(b).IsDead())
		{
			if (b > 0)
			{
				bulletList.erase(bulletList.begin() + b);
				b--;
			}
			else if (b == 0)
			{
				bulletList.clear();
			}
		}
	}

	//angle = 90;
	/*if (Target() != NULL || trys.velocity.X != -99.0f)
	{
		//std::cout << "rotate: " << targets->center.X << std::endl;

		Vector2 direction;// = center - targets.center;

		direction.X = -center.X + trys.center.X;
		direction.Y = -center.Y + trys.center.Y;

		float val = 1.0f / (float)sqrt((direction.X * direction.X) + (direction.Y * direction.Y));
		direction.X *= val;
		direction.Y *= val;

		angle = (float)atan2(-direction.X, direction.Y);
		angle = angle * (180.0f / 3.14159f) - 180.0f;
		angle = 0;
		angle += 1;
		//RotateToTarget();

		if (!IsInRange(trys.center) || trys.IsDead())
		{
			targets = NULL;
			trys.velocity.X = -99.0f;
			delta = 0;
			oldTime = time;
		}
	}*/
}

std::deque<Enemy> Tower::GetCopy()
{
	return copy;
}

