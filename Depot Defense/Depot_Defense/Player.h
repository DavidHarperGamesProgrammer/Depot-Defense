#pragma once
#include "Animation.h"
#include "GameObject.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Text.h"
#include <fstream>
#include "Background.h"
#include "ScreenManager.h"
#include "InputManager.h"


using namespace std;

class Player : public GameObject
{
public:
	Player();
	virtual ~Player() override;

	// Inherited via GameObject
	void Init();
	virtual void Update() override;
	virtual void Render() override;

	void setScore(int _score) { score.Score = _score; }
	void setLives(int _lives) { lives = _lives; }
	void setMoney(int _money) { money = _money; }

	int getScore() { return score.Score; }
	int getLives() { return lives; }
	int getMoney() { return money; }


private:
	//int score;
	int lives;
	int money;

	Text Lives;
	Text Money;

	bool nameInput = false;
	Text name;
	//string Name;

	Text Instructions1;
	Text Instructions2;

	Background background;

	struct PlayerScore
	{
		string Name;
		int Score;
	};

	PlayerScore score;


};

