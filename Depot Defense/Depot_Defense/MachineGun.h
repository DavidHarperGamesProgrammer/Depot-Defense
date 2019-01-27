#pragma once
#include "Tower.h"
#include <glm.hpp>
#include <vector>

class MachineGun : public Tower
{
public:
	MachineGun();
	MachineGun(glm::vec2 _position);
	~MachineGun();

	// Inherited via Tower
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Upgrade() override;

	void shoot();
	
	vector<Bullet*> bullets;


private:

	
	
	
};

