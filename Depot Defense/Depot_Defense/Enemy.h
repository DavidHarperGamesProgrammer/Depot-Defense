#pragma once

#include <iostream>
#include <glm.hpp>
#include "Sprite.h"
#include "Sphere.h"
#include <queue>

using namespace std;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;

	// setters
	void SetPosition(glm::vec2 Pos) { position = Pos; }
	void SetHealth(int Health) { health = Health; }
	void SetSpeed(int Speed) { speed = Speed; }
	void SetDirection(float Dir) { direction = Dir; }
	void SetAlive(bool alive) { isAlive = alive; }
	

	// getters 
	glm::vec2 GetPosition() { return position; }
	int GetHealth() { return health; }
	int GetSpeed() { return speed; }
	float GetDirection() { return direction; }
	bool IsAlive() { return isAlive; }
	bool Survived() { return survived; }


	void hit(int damage) { health -= damage; }

	Sphere sphere;

protected:
	glm::vec2 position;
	glm::vec2 Spawn;
	glm::vec2 Goal;
	queue<glm::vec2> Route;
	int health;
	int speed;
	bool isAlive;
	bool survived;
	float direction;
	Sprite sprite;
	
	enum Dir {UP,DOWN,LEFT,RIGHT};
	Dir dir;
};

