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

/*void Sprite::Draw()
{
	//std::cout << position.X << ", " << position.Y << std::endl;

	glBindTexture(GL_TEXTURE_2D, texture);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	/*if (change <= -0.545f)
	{
	tempChange = change;
	//change = 0;
	glTranslatef(-1.8f, change, 0.0f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
	glTranslatef(-1.8f, change, 0.0f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	}//////////

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(position.X, position.Y);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(position.X, position.Y - 0.18f);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(position.X + 0.18f, position.Y - 0.18f);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(position.X + 0.18f, position.Y);
	glEnd();
	glPopMatrix();


	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	glDisable(GL_TEXTURE_2D);
	//redraw();
}*/

void Sprite::Updates()
{

}