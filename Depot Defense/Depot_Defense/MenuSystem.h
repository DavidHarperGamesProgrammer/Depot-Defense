#pragma once
#include "Text.h"
#include "Background.h"
#include "AABB.h"
#include "InputManager.h"

class MenuSystem
{
public:
	MenuSystem();
	virtual ~MenuSystem() = 0;

	virtual void Draw() = 0;
	virtual void Update() = 0;

	

protected:
	Text title;
	//Background background;

	// sets a struct for the buttons
	struct Button
	{
		Text text;
		AABB box;
	};

	
};

