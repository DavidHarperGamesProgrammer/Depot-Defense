#pragma once
#include "GameState.h"
#include "Game.h"
#include "Player.h"

class PauseState : public GameState
{
public:
	PauseState(GameState* previousState);
	~PauseState();

	// Inherited via GameState
	virtual bool Draw() override;
	virtual bool Update() override;
	virtual bool OnEnter() override;
	virtual bool OnExit() override;
private:

	Background background;
	Text title;
	Text pause;

	struct Button
	{
		Text text;
		AABB box;
	};

	Button Menu;
	Button Continue;

	glm::vec2 MenuPos;
	glm::vec2 ContinuePos;

	

	
};

