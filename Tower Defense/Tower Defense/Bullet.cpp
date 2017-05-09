#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

bool Bullet::IsDead()
{
	return age > 200;
}

void Bullet::init(Vector2 position, float rotation, float speed, int damage)//, Enemy enemies, Vector2 enemypos)
{
	this->position = position;
	this->rotation = rotation;
	this->damage = damage;
	this->speed = speed;
	this->age = 100;
}

void Bullet::Kill()
{
	this->age = 1000;
}

void Bullet::Updates()
{
	//std::cout << "NO Enemy " << bulletVec.size() << std::endl;

	/*for (int i = 0; i < bulletVec.size(); i++)
	{
		//Bullet bull = bulletVec.at(i);
		//bulletVec.at(i).SetRotation(bulletVec.at(i).rotation);
		//bulletVec.at(i).velocity = Vector2().Transform(Vector2(0, -bulletVec.at(i).speed), Matrix().CreateRotationZ(bulletVec.at(i).rotation));
		float dx = bulletVec.at(i).enemypos.X - bulletVec.at(i).position.X;
		float dy = bulletVec.at(i).enemypos.Y - bulletVec.at(i).position.Y;
		bulletVec.at(i).velocity.X = dx;
		bulletVec.at(i).velocity.Y = dy;
		bulletVec.at(i).velocity.Normalize();
		
		bulletVec.at(i).velocity.X = bulletVec.at(i).velocity.X * (bulletVec.at(i).speed * 2.0f);
		bulletVec.at(i).velocity.Y = bulletVec.at(i).velocity.Y * (bulletVec.at(i).speed * 2.0f);

		if (Vector2().Distance(bulletVec.at(i).center, bulletVec.at(i).enemies.center) < 0.18f)
		{
			//bulletVec.at(i).enemies.currentHealth -= bulletVec.at(i).damage;
			//bulletVec.at(i).Kill();
		}
		std::cout << "S " << bulletVec.at(i).enemies.center.X << ", " << bulletVec.at(i).enemies.center.Y << ", " << bulletVec.at(i).enemies.currentHealth << ", " << enemies.currentHealth << std::endl;


		if (bulletVec.at(i).IsDead() && i > 0)//&& bulletVec.size() > 1)
		{
			//std::cout << "INDEX: " << i << ", " << bulletVec.size() << std::endl;
			bulletVec.erase(bulletVec.begin() + i);
			//std::cout << "INDEX2: " << i << ", " << bulletVec.size() << std::endl;
			//if (i > 0)
			i--;
			//std::cout << "INDEX3: " << i << ", " << bulletVec.size() << std::endl;
		}
		else if (bulletVec.at(i).IsDead() && i == 0)
		{
			bulletVec.clear();
			break;
		}
		std::cout << "BULVEC: " << bulletVec.at(i).speed << ", " << bulletVec.at(i).velocity.X << ", " << bulletVec.at(i).velocity.Y << std::endl;

		if (bulletVec.at(i).velocity.X == bulletVec.at(i).velocity.X * -1)
		{
			std::cout << "ZERO" << std::endl;
		}
		
		bulletVec.at(i).age++; 
		bulletVec.at(i).position += bulletVec.at(i).velocity;
		//if (bulletVec.at(i).position == bulletVec.at(i).position)
		//std::cout << "VELOCITY: " << bulletVec.at(i).speed << ", " << bulletVec.at(i).velocity.X << ", " << bulletVec.at(i).velocity.Y << std::endl;
	}*/
	//Draw();

	age++;
	position.X += velocity.X;
	position.Y += velocity.Y;

	//Draw();
}

void Bullet::SetRotation(float val)
{
	rotation = val;
	//std::cout << "rotation: " << rotation << std::endl;
	velocity = Vector2().Transform(Vector2(0, -speed), Matrix().CreateRotationZ(rotation));
}
