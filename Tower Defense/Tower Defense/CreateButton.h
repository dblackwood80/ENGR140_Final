#ifndef CREATEBUTTON_H
#define CREATEBUTTON_H

#include <vector>
#include "freeglut.h"

class CreateButton
{
public:
	float x, y, width, height;

public:

	CreateButton();
	~CreateButton();
	CreateButton(float x, float y, float width, float height);
	CreateButton(float x, float y, float width, float height, GLuint tex);

	void init(float x, float y, float width, float height, GLuint texture);

	bool Contains(float x, float y, std::vector<CreateButton>& button);
	bool Contains(float x, float y, CreateButton button);
	GLuint ContainsTexture(float x, float y, std::vector<CreateButton>& button);
	void DrawButton(std::vector<CreateButton>& button);

	void DrawTexturedButton(CreateButton button, GLuint texture);

	GLuint texture;

};


#endif // !CREATEBUTTON_H
