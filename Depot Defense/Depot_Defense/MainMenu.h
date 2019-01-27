#pragma once
#include "MenuSystem.h"

class MainMenu : public MenuSystem
{
public:
	MainMenu();
	virtual ~MainMenu() override;

	virtual void Draw() override;
	virtual void Update() override;

	// checks for state changes within the menus
	bool Quitting() { return quitting; }
	bool instruction() { bool temp = instructions; instructions = false; return temp; }
	bool credit() { bool temp = credits; credits = false; return temp; }
	bool starting() { bool temp = start; start = false; return temp; }
	bool Scores() { bool temp = scores; scores = false; return temp; }
private:
	
	// creates all the buttons
	Button Start;
	Button Instructions;
	Button Credits;
	Button Quit;
	Button HighScores;

	// sets all the checks for changin states
	bool quitting = false;
	bool instructions = false;
	bool credits = false;
	bool start = false;
	bool scores = false;
	// sets the positon vectors
	glm::vec2 StartPos;
	glm::vec2 InstructionsPos;
	glm::vec2 CreditsPos;
	glm::vec2 QuitPos;
	glm::vec2 HighScoresPos;

	

};

