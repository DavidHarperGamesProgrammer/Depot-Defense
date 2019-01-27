#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Sprite.h"
#include "AABB.h"
#include "Rock.h"
#include "Plant.h"
#include "Crater.h"


using namespace std;

class LevelMaker
{
public:
	LevelMaker();
	virtual ~LevelMaker() = 0;

	virtual void Draw() = 0;
	virtual void Update() = 0;

	glm::vec2 getSpawn() { return spawn; }
	glm::vec2 getGoal() { return goal; }

protected:

	// sets a struct to track the turret locations
	struct TurretLocation
	{
		glm::vec2 Position;
		AABB LocationBox;
	};


	glm::vec2 spawn;
	glm::vec2 goal;

	// sets up vectors to track all objects on the level
	vector<Rock*> Rocks;
	vector<Plant*> Plants;
	vector<Crater*> Craters;
	vector<Sprite*> MapChunks;
	
	// queue to creat the route on the map
	queue<glm::vec2> Route;
	
	// tracks all of the turret locations in a vector
	vector<TurretLocation*> TurretLocations;
};

