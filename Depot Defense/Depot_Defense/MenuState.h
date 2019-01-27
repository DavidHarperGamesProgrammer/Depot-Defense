#pragma once
#include "GameState.h"
#include "MainMenu.h"
#include "Instructions.h"
#include "Credits.h"


class MenuState : public GameState
{
public:
	MenuState(GameState* previousState);
	virtual ~MenuState() override;

	// Inherited via GameState
	virtual bool Draw() override;
	virtual bool Update() override;
	virtual bool OnEnter() override;
	virtual bool OnExit() override;
private:

	// creates all menus
	MainMenu _MainMenu;
	Instructions instructions;
	Credits credits;

	// sets state for menus
	enum State { Main, Instruct, Credits};
	State state = Main;

	Background background;

	
};

