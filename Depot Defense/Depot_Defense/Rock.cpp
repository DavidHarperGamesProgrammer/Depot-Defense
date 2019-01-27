#include "Rock.h"



Rock::Rock()
{
	// creates a randum number and uses it top create a rock
	RandAngle = rand() % 360;
	int RandNum = rand() % 3 + 20;
	rock.SetTexture("TileSheet");
	rock.SetSpriteDimension(100, 100);
	rock.SetTextureDimension(23, 13, 64, 64);
	rock.SetTextureCell(RandNum, 5);

	
}


Rock::~Rock()
{
}

void Rock::Update()
{
}

void Rock::Render()
{
	// draws the rock at a random angle
	rock.Draw(position.x, position.y, RandAngle);
}
