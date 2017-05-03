#include "PlasmaTower.h"

PlasmaTower::PlasmaTower()
{
}

PlasmaTower::~PlasmaTower()
{
}

void PlasmaTower::init(GLuint Texture, Vector2 position)
{
	this->damage = 15;
	this->cost = 15;

	this->radius = 0.03f;
}

void PlasmaTower::Update()
{
	if (delta > 750 && Target() != NULL)
	{
		Bullet bullet;
		//bullet.init(Vector2().Subtract(center, Vector2(0.09)), angle, 6, damage, bullet.enemyPosition);
		
		bullet.bulletVec.push_back(bullet);
		delta = 0;
		oldTime = time;
		bulletSize = bullet.bulletVec.size();
		bullet.Updates();
	}

	for (int i = 0; i < bulletSize; i++)
	{
		Bullet bullet = bullet.bulletVec[i];

		bullet.SetRotation(angle);
		bullet.Updates();

		if (!IsInRange(bullet.center))
		{
			bullet.Kill();
		}

		if (bullet.IsDead())
		{
			bullet.bulletVec.erase(bullet.bulletVec.begin() + i);
			i--;
		}
	}
}
