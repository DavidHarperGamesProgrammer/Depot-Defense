#include "Crater.h"



Crater::Crater()
{
	// creates a randum number and uses it top create a crater
	RandAngle = rand() % 360;
	int RandNum = rand() % 3 + 19;
	crater.SetTexture("TileSheet");
	crater.SetSpriteDimension(100, 100);
	crater.SetTextureDimension(23, 13, 64, 64);
	crater.SetTextureCell(RandNum, 0);
}


Crater::~Crater()
{
}

void Crater::Update()
{
}

void Crater::Render()
{
	crater.Draw(position.x, position.y, RandAngle);
}
