#include "MenuState.h"
#include "Game.h"


MenuState::MenuState(GameState* previousState) : GameState(previousState)
{
	isAlive = true;
	isActive = true;
	background.create();
}


MenuState::~MenuState()
{
}

bool MenuState::Draw()
{
	//updates and draws the menu of the current state
	background.Render();
	switch (state)
	{
	case Main:
		_MainMenu.Update();
		_MainMenu.Draw();
		break;
	case Instruct:
		instructions.Update();
		instructions.Draw();
		break;
	case Credits:
		credits.Update();
		credits.Draw();
		break;
		
	}
	return false;
}

bool MenuState::Update()
{
	background.PlayMusic();
	const Uint8* keys = nullptr;
	//read keyboard state
	keys = TheInput::Instance()->GetKeyStates();
	//if escape key is pressed flag game to end
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		isAlive = isActive = false;
	}
	//if game window's top right X is clicked flag game to end
	if (TheInput::Instance()->IsXClicked())
	{
		isAlive = isActive = false;
	}
	// all the checks to see if the state is changing
	if (_MainMenu.Quitting())
	{
		isAlive = isActive = false;
	}
	else if (_MainMenu.instruction())
	{
		state = Instruct;
	}
	else if (_MainMenu.credit())
	{
		state = Credits;
	}
	else if (_MainMenu.starting())
	{
		isAlive = isActive = false;
		background.Destroy();
		TheGame::Instance()->changeState(new PlayState(this));
	}
	else if (_MainMenu.Scores())
	{
		isActive = false;
		state = Main;
		TheGame::Instance()->addState(new ScoresState(this));
	}

	if (instructions.menu())
	{
		state = Main;
	}
	else if (instructions.starting())
	{
		isAlive = isActive = false;
		background.Destroy();
		TheGame::Instance()->changeState(new PlayState(this));
	}

	if (credits.menu())
	{
		state = Main;
	}
	else if (credits.starting())
	{
		isAlive = isActive = false;
		background.Destroy();
		TheGame::Instance()->changeState(new PlayState(this));
	}
	
	return false;
}

bool MenuState::OnEnter()
{
	return false;
}

bool MenuState::OnExit()
{
	return false;
}
