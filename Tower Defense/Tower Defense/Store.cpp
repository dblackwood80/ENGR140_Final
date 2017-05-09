#include "Store.h"
#include "freeglut.h"
#include <iostream>

Store::Store()
{
	upgrade.init(-1.0f, -0.77, 0.4f, 0.1f, NULL);
	startWave.init(-0.2f, -0.77f, 0.4f, 0.1f, NULL);
	upgradeButtons.push_back(upgrade);
	startButtons.push_back(startWave);
}

Store::~Store()
{
}

void Store::Draw(int money, float centerX, float centerY, float radius)
{
	moneyString = std::to_string(money);

	strcpy((char*)moneyChar, moneyString.c_str());

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(-0.98f, -0.67f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"MONEY: ");
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)moneyChar);

	if (waveStarted == false)
	{
		glRasterPos2f(-0.13f, -0.835f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"Start Wave");
		startWave.DrawButton(startButtons);
	}

	/*glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(-0.98f, -0.67f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"Level: ");
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)moneyChar);*/

	if (showStats)
	{
		/*glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(-0.48f, -0.87f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"ONE PLAYER");

		glRasterPos2f(0.0125f, -0.87f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"TWO PLAYER");*/

		glColor3f(1.0f, 1.0f, 1.0f);
		glRasterPos2f(-0.93f, -0.837f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char *)"UPGRADE");
		upgrade.DrawButton(upgradeButtons);

		glColor3f(1.0f, 1.0f, 1.0f);

		glBegin(GL_LINE_LOOP);
		glEnable(GL_LINE_SMOOTH);
		for (double d = 0; d < max; d += inc)
		{
			glVertex2f(cos(d) * (radius * 0.6f) + centerX-0.09, sin(d) * (radius * 0.6f) + centerY+0.07);
		}

		glEnd();
		glDisable(GL_LINE_SMOOTH);
	}

	glColor3f(0.75f, 0.75f, 0.75f);

	glBegin(GL_QUADS);

	glVertex2f(-1.0f, -0.62f); //0.0f, 0.0f
	glVertex2f(1.0f, -0.62f); //0.4f, 0.0f
	glVertex2f(1.0f, -1.0f); //0.4f, -0.1f
	glVertex2f(-1.0f, -1.0f);

	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
}

void Store::init(Wave wave)
{
	this->wave = wave;
}

void Store::Reset()
{

}
