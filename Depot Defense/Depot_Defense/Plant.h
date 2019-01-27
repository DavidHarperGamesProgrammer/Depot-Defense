#pragma once
#include <ctime>
#include <cstdlib>
#include "GameObject.h"
#include "Sprite.h"
#include "TextureManager.h"

class Plant : public GameObject
{
public:
	Plant();
	virtual ~Plant() override;

	virtual void Update() override;
	virtual void Render() override;

private:
	int RandAngle;
	Sprite plant;
};

