#pragma once
#include "MenuSystem.h"
class Instructions :
	public MenuSystem
{
public:
	Instructions();
	virtual ~Instructions() override;

	virtual void Draw() override;
	virtual void Update() override;

	bool starting() { bool temp = start; start = false; return temp; }
	bool menu() { bool temp = mainmenu; mainmenu = false; return temp; }

private:
	// creates all text
	Text line1;
	Text line2;
	Text line3;
	Text line4;

	// creates all the buttons
	Button Start;
	Button Mainmenu;

	glm::vec2 StartPos;
	glm::vec2 MainmenuPos;

	bool mainmenu = false;
	bool start = false;
	

};

