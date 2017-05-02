#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

bool Bullet::IsDead()
{
	return age > 500;
}

void Bullet::init(Vector2 position, float rotation, float speed, int damage, Vector2 enemyPosition)
{
	this->position = position;
	this->rotation = rotation;
	this->damage = damage;
	this->speed = speed;
	this->enemyPosition = enemyPosition;
	this->age = 100;
}

void Bullet::Kill()
{
	this->age = 400;
}

void Bullet::Updates()
{
	std::cout << "NO Enemy " << bulletVec.size() << std::endl;

	for (int i = 0; i < bulletVec.size(); i++)
	{
		//Bullet bull = bulletVec.at(i);
		//bulletVec.at(i).SetRotation(bulletVec.at(i).rotation);
		//bulletVec.at(i).velocity = Vector2().Transform(Vector2(0, -bulletVec.at(i).speed), Matrix().CreateRotationZ(bulletVec.at(i).rotation));
		float dx = bulletVec.at(i).enemyPosition.X - bulletVec.at(i).position.X;
		float dy = bulletVec.at(i).enemyPosition.Y - bulletVec.at(i).position.Y;
		bulletVec.at(i).velocity.X = dx;
		bulletVec.at(i).velocity.Y = dy;
		bulletVec.at(i).velocity.Normalize();
		
		bulletVec.at(i).velocity.X = bulletVec.at(i).velocity.X * bulletVec.at(i).speed;
		bulletVec.at(i).velocity.Y = bulletVec.at(i).velocity.Y * bulletVec.at(i).speed;

		if (bulletVec.at(i).IsDead()) //&& bulletVec.size() > 1)
		{
			//std::cout << "INDEX: " << i << ", " << bulletVec.size() << std::endl;
			bulletVec.erase(bulletVec.begin() + i);
			//std::cout << "INDEX2: " << i << ", " << bulletVec.size() << std::endl;
			if (i > 0)
			i--;
			//std::cout << "INDEX3: " << i << ", " << bulletVec.size() << std::endl;
		}

		bulletVec.at(i).age++;
		bulletVec.at(i).position += bulletVec.at(i).velocity;
		if (bulletVec.at(i).position == bulletVec.at(i).enemyPosition)
		std::cout << "VELOCITY: " << bulletVec.at(i).position.X << ", " << bulletVec.at(i).position.Y << std::endl;
	}
	Draw();
}

void Bullet::SetRotation(float val)
{
	rotation = val;

	velocity = Vector2().Transform(Vector2(0, -speed), Matrix().CreateRotationZ(rotation));
}

void Bullet::Draw()
{
	for (int i = 0; i < bulletVec.size(); i++)
	{
		glPointSize(10);
		glBegin(GL_POINTS);

		glVertex2f(bulletVec.at(i).position.X, bulletVec.at(i).position.Y);

		glEnd();
	}



}
