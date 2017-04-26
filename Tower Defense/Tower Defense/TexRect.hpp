//
//  TexRect.hpp
//  glutapp
//
//  Created by Angelo Kyrilov on 4/11/17.
//  Copyright © 2017 Angelo Kyrilov. All rights reserved.
//

#ifndef TexRect_hpp
#define TexRect_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <vector>
#include "Tower.h"

class TexRect {
    float x;
    float y;
    float w;
    float h;
    
public:
    TexRect (float x=0, float y=0, float w=0.5, float h=0.5){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    
    
void draw(float tileWidth, float tileHeight) {
	//std::cout << x << ", " << y << std::endl;
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y - tileHeight);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + tileWidth, y - tileHeight);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + tileWidth, y);

	glEnd();
    glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y - tileHeight);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + tileWidth, y - tileHeight);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + tileWidth, y);

	glEnd();
}

bool Contains(float x, float y, std::vector<Tower>& tower)
{
	for (int i = 0; i < tower.size(); i++)
	{
		if (x >= tower.at(i).x && x < tower.at(i).x + tower.at(i).width)
		{
			if (y > tower.at(i).y - tower.at(i).height && y <= tower.at(i).y)
			{
				std::cout << x << " " << y << " good " << std::endl;
				return true;
			}

		}
	}
	return false;
}

};

#endif /* TexRect_hpp */
