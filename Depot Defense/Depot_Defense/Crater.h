#pragma once
#include "GameObject.h"
#include <ctime>
#include <cstdlib>
#include "Sprite.h"
#include "TextureManager.h"

class Crater : public GameObject
{
public:
	Crater();
	virtual ~Crater() override;

	virtual void Update() override;
	virtual void Render() override;

private:
	int RandAngle;
	Sprite crater;
};

