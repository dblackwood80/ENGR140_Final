#ifndef TOWER_H
#define TOWER_H

#include <vector>

class Tower
{
public:

	Tower();
	Tower(float x, float y);
	~Tower();

	void Draw(std::vector<Tower>& tower);
	bool Contains(float x, float y, std::vector<Tower>& tower);
	bool InBounds(float y);
	void DeleteTower(float x, float y, std::vector<Tower>& tower);

	float x, y;
	

};


#endif // !TOWER_H
