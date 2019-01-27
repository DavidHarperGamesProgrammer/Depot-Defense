#pragma once
#include "GameState.h"
#include "Game.h"

class ScoresState :
	public GameState
{
public:

	ScoresState(GameState* previousState);
	virtual ~ScoresState() override;

	// Inherited via GameState
	virtual bool Draw() override;
	virtual bool Update() override;
	virtual bool OnEnter() override;
	virtual bool OnExit() override;

private:
	
	

	Background background;
	Text title;
	int scorecount = 0;

	struct Button
	{
		Text text;
		AABB box;
	};

	struct Score
	{
		string name;
		int score;
	};

	struct {
		bool operator()(Score* a, Score* b) const
		{
			return a->score > b->score;
		}
	} customMore;

    bool Sort(const Score& i, const Score& j) { return (i.score < j.score); }

	vector<Score*> HighScores;

	Button Menu;
	Button Quit;

	glm::vec2 MenuPos;
	glm::vec2 QuitPos;

	vector<Text*> highscores;

};

