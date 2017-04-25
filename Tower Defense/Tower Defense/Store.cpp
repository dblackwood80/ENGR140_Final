#include "Store.h"
#include "freeglut.h"

Store::Store()
{
}

Store::~Store()
{
}

void Store::Draw()
{
	glColor3f(0.75f, 0.75f, 0.75f);

	glBegin(GL_QUADS);

	glVertex2f(-1.0f, -0.62f); //0.0f, 0.0f
	glVertex2f(1.0f, -0.62f); //0.4f, 0.0f
	glVertex2f(1.0f, -1.0f); //0.4f, -0.1f
	glVertex2f(-1.0f, -1.0f);

	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
}
