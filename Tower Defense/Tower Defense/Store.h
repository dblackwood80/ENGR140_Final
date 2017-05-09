#ifndef STORE_H
#define STORE_H

#include "CreateButton.h"
#include "Wave.h"
#include <string>

class Store
{
public:

	Store();
	~Store();

	void Draw(int money, float centerX, float centerY, float radius);
	void init(Wave wave);
	Wave wave;

	unsigned char moneyChar[10];
	std::string moneyString;

	unsigned char levelChar[10];
	std::string levelString;

	bool showStats = false;

	CreateButton upgrade, startWave;
	std::vector<CreateButton> upgradeButtons, startButtons;

	double inc = 3.14159 / 12;
	double max = 2 * 3.14159;

	bool waveStarted = false;

	void Reset();
};

#endif // !STORE_H
