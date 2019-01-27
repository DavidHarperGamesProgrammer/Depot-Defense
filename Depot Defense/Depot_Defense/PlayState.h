#pragma once
#include "GameState.h"
#include "Level_1.h"
#include "Game.h"
#include "Background.h"
#include "Audio.h"

class PlayState : public GameState
{
public:
	PlayState(GameState* previousState);
	virtual ~PlayState() override;

	// Inherited via GameState
	virtual bool Draw() override;
	virtual bool Update() override;
	virtual bool OnEnter() override;
	virtual bool OnExit() override;




private:
	Audio Layer1;
	Audio Layer2;
	Level_1 level1;
		
};

