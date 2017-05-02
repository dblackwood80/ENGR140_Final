#include "CreateButton.h"
#include "freeglut.h"
#include <iostream>

bool CreateButton::Contains(float x, float y, std::vector<CreateButton>& button)
{
	for (int i = 0; i < button.size(); i++)
	{
		if (x >= button.at(i).x && x < button.at(i).x + button.at(i).width)
		{
			if (y > button.at(i).y - button.at(i).height && y <= button.at(i).y)
			{
				std::cout << x << " " << y << " good " << std::endl;
				return true;
			}

		}
	}
	return false;
}

CreateButton::CreateButton(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	/*glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(-0.365f, -0.07f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"PLAY");

	glRasterPos2f(0.14f, -0.07f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"EXIT");

	*/

	

	//GLuint texture; //the array for our texture
	//GLuint texture2; //the array for our second texture
}

void CreateButton::init(float x, float y, float width, float height, GLuint texture)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->texture = texture;
}

void CreateButton::DrawButton(std::vector<CreateButton>& button)
{
	for (int i = 0; i < button.size(); i++)
	{
		glColor3f(0.0f, 0.0f, 0.0f);

		glBegin(GL_QUADS);

		glVertex2f(button.at(i).x, button.at(i).y); //0.0f, 0.0f
		glVertex2f(button.at(i).x + button.at(i).width, button.at(i).y); //0.4f, 0.0f
		glVertex2f(button.at(i).x + button.at(i).width, button.at(i).y - button.at(i).height); //0.4f, -0.1f
		glVertex2f(button.at(i).x, button.at(i).y- button.at(i).height);

		glEnd();
		//std::cout "X: " << x << ", " << this->x 
	}
}

void CreateButton::DrawTexturedButton(std::vector<CreateButton>& button, GLuint texture)
{
	for (int i = 0; i < button.size(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, button.at(i).texture);
		//std::cout << texture << std::endl;

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glBegin(GL_QUADS);

		glVertex2f(button.at(i).x, button.at(i).y); //0.0f, 0.0f
		glVertex2f(button.at(i).x + button.at(i).width, button.at(i).y); //0.4f, 0.0f
		glVertex2f(button.at(i).x + button.at(i).width, button.at(i).y - button.at(i).height); //0.4f, -0.1f
		glVertex2f(button.at(i).x, button.at(i).y - button.at(i).height);

		glEnd();

		glDisable(GL_TEXTURE_2D);
	}
}

CreateButton::CreateButton()
{
}

CreateButton::~CreateButton()
{

}
