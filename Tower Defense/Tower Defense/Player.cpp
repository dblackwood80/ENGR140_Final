#include "Player.h"

Player::Player()
{
	
}

void Player::init(Level level, GLuint towerTexture)
{
	this->level = level;
	this->towerTexture = towerTexture;
}

Player::~Player()
{
}

int Player::Money()
{
	return money;
}

int Player::Lives()
{
	return lives;
}

void Player::Draw()
{
	for (int i = 0; i < towers.size(); i++)
	{
		for (int b = 0; b < towers.at(i).bulletList.size(); b++)
		{
			glPointSize(10);

			glBegin(GL_POINTS);

			glVertex3f(towers.at(i).bulletList.at(b).position.X, towers.at(i).bulletList.at(b).position.Y, -1.0f);

			glEnd();
		}
		towers.at(i).Draw();
	}
	//std::cout << "TOws " << towers.size() << std::endl;
	
	/*for (int j = 0; j < bulletList.size(); j++)
	{
		bulletList.at(j).Draw();
	}*/

	//manager.Updates();
}

bool Player::InBounds(float y)
{
	if (y > -0.62f + height)
	{
		return true;
	}

	return false;
}

bool Player::Contains(float x, float y)
{
	for (int i = 0; i < towers.size(); i++)
	{
		if (x >= towers.at(i).position.X - (towers.at(i).width / 2) && x < towers.at(i).position.X + (towers.at(i).width / 2))
		{
			if (y > towers.at(i).position.Y - (towers.at(i).height / 2) && y <= towers.at(i).position.Y + (towers.at(i).height / 2))
			{
				return true;
			}

		}
	}

	return false;
}

Tower Player::ContainsTower(float x, float y)
{
	for (int i = 0; i < towers.size(); i++)
	{
		if (x >= towers.at(i).position.X - (towers.at(i).width / 2) && x < towers.at(i).position.X + (towers.at(i).width / 2))
		{
			if (y > towers.at(i).position.Y - (towers.at(i).height / 2) && y <= towers.at(i).position.Y + (towers.at(i).height / 2))
			{
				return towers.at(i);
			}

		}
	}
}

/*void Player::Updates(std::deque<Enemy> & enemies)
{
	for (int i = 0; i < towers.size(); i++)
	{
		for (int j = 0; j < enemies.size(); j++)
		{
			enemies.at(j).center.X = enemies.at(j).position.X + 0.09f;
			enemies.at(j).center.Y = enemies.at(j).position.Y - 0.09f;
			//std::cout << "ID: " << enemies.at(j).ID << std::endl;
			//std::cout << "Range: " << Vector2().Distance(towers.at(i).center, enemies.at(j).center) << " < " << towers.at(i).radius << std::endl;
			//std::cout << "ALIVE: " << enemies.front().alive << std::endl;
		}

		//if (Vector2().Distance(towers.at(i).center, enemies.at(j).center) < towers.at(i).radius)
		//{

		if (towers.at(i).copy.size() > 5)
		{
			towers.at(i).GetEnemy(towers.at(i).copy);
		}
		else
		{
			towers.at(i).GetEnemy(enemies);
			//std::cout << "OLD" << std::endl;
		}

		//}
		
		//std::cout << "sizes " << enemy.size() << std::endl;

		towers.at(i).Updates();
	}
}*/

std::deque<Enemy> Player::Ups(std::deque<Enemy> ty)
{
	return std::deque<Enemy>();
}
