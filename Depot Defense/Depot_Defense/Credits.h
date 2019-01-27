#pragma once
#include "MenuSystem.h"
class Credits :
	public MenuSystem
{
public:
	Credits();
	~Credits();

	virtual void Draw() override;
	virtual void Update() override;

	bool starting() { bool temp = start; start = false; return temp; }
	bool menu() { bool temp = mainmenu; mainmenu = false; return temp; }

private:
	// creates all the text for the menu
	Text TexCredit;
	Text SoundCredit;
	Text FontCredit;

	// creates the buttons for the menu
	Button Start;
	Button Mainmenu;

	glm::vec2 StartPos;
	glm::vec2 MainmenuPos;

	bool mainmenu = false;
	bool start = false;
};

