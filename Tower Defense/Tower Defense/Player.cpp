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

void Player::mouseMove(float x, float y)
{
	this->mouseX = x;
	this->mouseY = y;
}

int Player::Money()
{
	return money;
}

int Player::Lives()
{
	return lives;
}

float Player::ConvertX(float& x)
{
	// Converting window coordinates [0..width] x [0..height] to [-1..1] x [-1..1]
	x = (2.0f*(x / float(768))) - 1.0f;

	return x;
}

float Player::ConvertY(float &y)
{
	y = 1.0f - (2.0f*(y / float(768)));
	// Take care of issue in Windows where y coordinate is a little off
#if defined WIN32
	y -= 0.03;
#endif

	return y;
}

bool Player::ValidSpot()
{
	bool inBound = cellX >= 0 && cellY >= 0 && cellX < 11 && cellY < 9;
	bool areaClear = true;

	std::cout << "WHat" << mouseX << ", " << mouseY << std::endl;

	for (int i = 0; i < towers.size(); i++)
	{
		
		areaClear = (towers.at(i).position != Vector2(ConvertX(mouseX), ConvertY(mouseY)));

		if (!areaClear)
			break;
	}

//	bool onPath = (level.Index(cellX, cellY) != 1);

	return inBound && areaClear;//&& onPath;
}

void Player::Updates()
{
	if (ValidSpot())
	{
		Tower tower(towerTexture, Vector2(mouseX, mouseY));
		towers.push_back(tower);
	}

	for (int i = 0; i < towers.size(); i++)
	{

	}
}