#ifndef TOWER_H
#define TOWER_H

#include <vector>

class Tower
{
public:
	float x, y;

public:

	Tower();
	~Tower();
	Tower(float x, float y);

	void Draw(std::vector<Tower>& tower);
	bool Contains(float x, float y, std::vector<Tower>& tower);
	bool InBounds(float y);
	void DeleteTower(float x, float y, std::vector<Tower>& tower);

};


#endif // !TOWER_H
