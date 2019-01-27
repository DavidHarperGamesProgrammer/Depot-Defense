#pragma once
#include "LevelMaker.h"
#include "Soldier.h"
#include "MachineGun.h"
#include "InputManager.h"
#include "Player.h"


class Level_1 : public LevelMaker
{
public:
	Level_1();
	virtual ~Level_1() override;

	// Inherited via LevelMaker
	virtual void Draw() override;
	virtual void Update() override;

	int getWave() { return wave; }

	Player player;

private:

	const Uint8* keys = nullptr;

	bool firstenemy;

	Text dir;

	

	//sets up all the propertiees used in the level
	int plantCount = 0;
	int rockCount = 0;
	int craterCount = 0;
	int enemycount = 0;
	int towercount = 0;
	int wave = 0;
	int wait = 0;
	int clickwait = 0;
	bool click = true;
	int upgradecount = 0;
	int enemycolour = 14;

	// stes all bool chekcs used in the level
	bool waveEnded = true;
	bool built0 = false;
	bool built1 = false;
	bool built2 = false;
	bool built3 = false;
	bool built4 = false;
	bool built5 = false;
	bool built6 = false;

	// sets the waypoints for the route through the level
	glm::vec2 waypoint1 = glm::vec2(950, 250);
	glm::vec2 waypoint2 = glm::vec2(950, 450);
	glm::vec2 waypoint3 = glm::vec2(1650, 450);
	glm::vec2 waypoint4 = glm::vec2(1650, 750);
	glm::vec2 waypoint5 = glm::vec2(650, 750);
	glm::vec2 waypoint6 = glm::vec2(650, 450);
	glm::vec2 waypoint7 = glm::vec2(350, 450);
	glm::vec2 waypoint8 = glm::vec2(350, 850);
	
	// creates a vecotr of soldiers and towers within the level
	vector<Soldier*> soldiers;
	vector<MachineGun*> Towers;


	// map of the level for the game to draw from
	int MapPlan[11][20] = { {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
						    {4, 4, 4, 4, 9, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
						    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7,11, 9, 4, 4, 4, 4, 4, 4, 4, 4},
						    {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4},
						    {4, 4, 9,10, 7, 7, 7,11, 4, 5, 6, 7, 7, 7, 7, 7, 7,11, 4, 4},
						    {4, 4, 4, 5, 0, 1, 2, 3, 4,12, 1, 1, 1, 1, 1, 1, 2, 3, 4, 4},
						    {4, 4, 4, 5, 3, 4, 5, 3, 4, 4, 4, 9, 4, 4, 4, 9, 5, 3, 4, 4},
						    {4, 4, 4, 5, 3, 9, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 3, 4, 4},
						    {7, 7, 7, 8, 3, 4,12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,13, 4, 4},
						    {1, 1, 1, 1, 13,4, 4, 4, 4, 4, 4, 4, 4, 9, 4, 4, 4, 4, 4, 4},
						    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4} };
};

