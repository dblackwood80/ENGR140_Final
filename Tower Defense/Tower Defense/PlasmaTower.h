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

	void Update();

	int bulletSize;

};


#endif // !PLASMATOWER_H
