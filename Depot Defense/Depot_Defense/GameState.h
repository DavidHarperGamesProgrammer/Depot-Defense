#pragma once
class GameState
{
public:
	GameState(GameState* previousState) { PreviousState = previousState; }
	virtual ~GameState() = 0;

	virtual bool OnEnter() = 0;
	virtual bool Draw() = 0;
	virtual bool Update() = 0;
	virtual bool OnExit() = 0;

	bool& IsActive() { return isActive; }
	bool& IsAlive() { return isAlive; }

protected:

	bool isActive;
	bool isAlive;
	GameState* PreviousState;
};

