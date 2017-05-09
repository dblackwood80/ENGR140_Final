#ifndef PLASMATOWER_H
#define PLASMATOWER_H

#include "Tower.h"
#include "Bullet.h"

class PlasmaTower : public Tower
{

public:
	PlasmaTower();
	~PlasmaTower();

	void init(GLuint Texture, Vector2 position);

	void draw();

	//void Update();

	int bulletSize;

	std::vector<Tower> tows;
};


#endif // !PLASMATOWER_H
