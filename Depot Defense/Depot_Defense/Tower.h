#pragma once
#include <iostream>
#include <glm.hpp>
#include "Sprite.h"
#include "Sphere.h"

using namespace std;

class Tower
{
public:
	Tower();
	virtual ~Tower() = 0;

	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Upgrade() = 0;

	// setters for towers
	void SetPosition(glm::vec2 Pos) { position = Pos; }
	void SetDirection(float Dir) { direction = Dir; }
	void SetBulletCount(int count) { bulletcount = count; }
	void SetFireCount(int count) { firecount = count; }
	// getters for towers
	glm::vec2 GetPosition() { return position; }
	float GetDirection() { return direction; }
	int GetFireRate() { return fireRate; }
	int GetDamage() { return damage; }
	int GetBaseNumber() { return baseNumber; }
	int GetBulletCount() { return bulletcount; }
	int GetFireCount() { return firecount; }

	// sphere for the towers attack radius
	Sphere attackRadius;

	


	

protected:
	// all variables needed for the tower
	glm::vec2 position;
	
	float direction;
	float range;
	int damage;
	int fireRate;
	int baseNumber;
	int bulletcount;
	int firecount;

	Sprite sprite;
	Sprite base;
	

	struct Bullet
	{
		Sprite bullet;
		glm::vec2 bulletPos;
		Sphere bulletBox;
		float bulletDir;
	};

	
};


