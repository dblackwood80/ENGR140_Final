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
		towers.at(i).Draw();
	}
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

void Player::Updates(std::deque<Enemy> enemies)
{
	for (int i = 0; i < towers.size(); i++)
	{
		if (towers.at(i).Target() == NULL)
		{
			towers.at(i).GetEnemy(enemies);
		}
		towers.at(i).Updates();
	}
}