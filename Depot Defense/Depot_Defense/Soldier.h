#pragma once
#include "Enemy.h"
class Soldier : public Enemy
{
public:
	Soldier();
	virtual ~Soldier();

	// Inherited via Enemy
	virtual void Update() override;
	virtual void Render() override;

	void Create(glm::vec2 spawn, glm::vec2 goal, queue<glm::vec2> route, int colour);



};

