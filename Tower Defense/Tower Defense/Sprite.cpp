#include "Sprite.h"

Sprite::Sprite(GLuint tex, Vector2 pos)
{
	texture = tex;

	position = pos;
	velocity = Vector2(0.0f, 0.0f); //Zero

	center = Vector2(position.X + 0.09f, position.Y + 0.09f);
	origin = Vector2(0.09f, 0.09f);
}

Sprite::~Sprite()
{
}

Vector2 Sprite::Center()
{
	return center;
}

void Sprite::Updates()
{

}