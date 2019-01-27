#pragma once
#include <ctime>
#include <cstdlib>
#include "GameObject.h"
#include "Sprite.h"
#include "TextureManager.h"

class Rock : public GameObject
{
public:
	Rock();
	virtual ~Rock() override;

	virtual void Update() override;
	virtual void Render() override;
	
private:
	int RandAngle;

	Sprite rock;
	
	

};

