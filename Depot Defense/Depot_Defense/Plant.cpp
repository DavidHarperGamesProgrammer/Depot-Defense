#include "Plant.h"



Plant::Plant()
{
	// creates a randum number and uses it top create a plant
	RandAngle = rand() % 360;
	int RandNum = rand() % 5 + 15;
	plant.SetTexture("TileSheet");
	plant.SetSpriteDimension(100, 100);
	plant.SetTextureDimension(23, 13, 64, 64);
	plant.SetTextureCell(RandNum, 5);
}


Plant::~Plant()
{
}

void Plant::Update()
{
}

void Plant::Render()
{
	plant.Draw(position.x,position.y, RandAngle);
}
