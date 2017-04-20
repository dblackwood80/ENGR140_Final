#ifndef CREATEBUTTON_H
#define CREATEBUTTON_H

#include <vector>

class CreateButton
{
public:
	float x, y, width, height;

public:

	CreateButton();
	~CreateButton();
	CreateButton(float x, float y, float width, float height);

	bool Contains(float x, float y, std::vector<CreateButton>& button);
	void DrawButton(std::vector<CreateButton>& button);

};


#endif // !CREATEBUTTON_H
