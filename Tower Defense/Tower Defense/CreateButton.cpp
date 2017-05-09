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

bool CreateButton::Contains(float x, float y, CreateButton button)
{
	if (x >= button.x && x < button.x + button.width)
	{
		if (y > button.y - button.height && y <= button.y)
		{
			std::cout << x << " " << y << " good " << std::endl;
			return true;
		}

	}

	return false;
}

GLuint CreateButton::ContainsTexture(float x, float y, std::vector<CreateButton>& button)
{
	for (int i = 0; i < button.size(); i++)
	{
		if (x >= button.at(i).x && x < button.at(i).x + button.at(i).width)
		{
			if (y > button.at(i).y && y <= button.at(i).y + button.at(i).height)
			{
				std::cout << x << " " << y << " good " << std::endl;
				return button.at(i).texture;
			}

		}
	}
	return NULL;
}

CreateButton::CreateButton(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

CreateButton::CreateButton(float x, float y, float width, float height, GLuint tex)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->texture = tex;
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
		
		glColor3f(1.0f, 1.0f, 1.0f);
	}
}

void CreateButton::DrawTexturedButton(CreateButton button, GLuint texture)
{
		glBindTexture(GL_TEXTURE_2D, texture);
		//std::cout << texture << std::endl;

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glBegin(GL_QUADS);

		glTexCoord2f(0.0, 0.0);
		glVertex2f(button.x, button.y); //0.0f, 0.0f
		
		glTexCoord2f(0.0, 1.0);
		glVertex2f(button.x, button.y + button.height);
		
		glTexCoord2f(1.0, 1.0);
		glVertex2f(button.x + button.width, button.y + button.height); //0.4f, -0.1f
		
		glTexCoord2f(1.0, 0.0);
		glVertex2f(button.x + button.width, button.y); //0.4f, 0.0f
		

		glEnd();

		glDisable(GL_TEXTURE_2D);
}

CreateButton::CreateButton()
{
}

CreateButton::~CreateButton()
{

}
