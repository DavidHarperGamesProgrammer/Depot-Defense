#pragma once
#include <SDL.h> 

#include <ctime>
#include <iostream>
#include <string>
#include <deque>

#include "Singleton.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include "TextureManager.h"

#include "Text.h"
#include <fstream>
#include "Player.h"

#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "ScoresState.h"

using namespace std;

class Game
{
public:

	/*MenuState* menu;
	
	PlayState* play;


	GameState* state;*/

	friend class Singleton<Game>;

	bool Init(string Name, int Width, int height);
	bool Run();
	void Shutdown();

	void addState(GameState* state);
	void changeState(GameState* state);

	int GetTotal() { return SDL_GetTicks(); }
	int GetElapsed() { return elapsedTime; }

	fstream Scores;

private:

	void removeState();

	Game();

	bool endGame = false;
	const Uint8* keys = nullptr;

	deque<GameState*> States;

	int elapsedTime;

	Text ET;
	
	fstream Times;
	

};

typedef Singleton<Game>TheGame;

