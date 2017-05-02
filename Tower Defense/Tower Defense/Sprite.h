#ifndef SPRITE_H
#define SPRITE_H
#include "freeglut.h"
#include "Vector2.h"

class Sprite 
{
public:
	Sprite(GLuint tex, Vector2 pos);
	~Sprite();

	Vector2 Center();

	void Updates();

public:
	GLuint texture;

	Vector2 position;
	Vector2 velocity;

	Vector2 center;
	Vector2 origin;

	float rotation;


};

#endif // !SPRITE_H
