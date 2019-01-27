#include "MachineGun.h"



MachineGun::MachineGun()
{
	position = glm::vec2(0, 0);
	
	// sets textures for the base
	base.SetTexture("TileSheet");
	base.SetSpriteDimension(100, 100);
	base.SetTextureDimension(23, 13, 64, 64);
	base.SetTextureCell(22, 7);


	//sets textures for the gun
	sprite.SetTexture("TileSheet");
	sprite.SetSpriteDimension(100, 100);
	sprite.SetTextureDimension(23, 13, 64, 64);
	sprite.SetTextureCell(19, 9);

	
	


	range = 200;
	damage = 2;
	fireRate = 25;
	bulletcount = 0;
	

	attackRadius.SetRadius(range);
	attackRadius.SetPosition(position.x, position.y);



}

MachineGun::MachineGun(glm::vec2 _position)
{
	position = _position;

	// sets textures for the base
	base.SetTexture("TileSheet");
	base.SetSpriteDimension(100, 100);
	base.SetTextureDimension(23, 13, 64, 64);
	base.SetTextureCell(22, 7);

	//sets textures for the gun
	sprite.SetTexture("TileSheet");
	sprite.SetSpriteDimension(100, 100);
	sprite.SetTextureDimension(23, 13, 64, 64);
	sprite.SetTextureCell(19, 9);

	range = 200;
	damage = 2;
	fireRate = 25;
	bulletcount = 0;
	baseNumber = 0;

	attackRadius.SetRadius(range);
	attackRadius.SetPosition(position.x, position.y);



}


MachineGun::~MachineGun()
{
}

void MachineGun::Draw()
{
	// draws the base and the gun of the tower in the correct ordre
	base.Draw(position.x, position.y);
	sprite.Draw(position.x , position.y, direction);

	for (auto b : bullets)
	{
		b->bullet.Draw(b->bulletPos.x, b->bulletPos.y);
	}

}

void MachineGun::Update()
{

	attackRadius.SetPosition(position.x + 50, position.y + 50);

	for (auto b : bullets)
	{

		float cosang = cos(glm::radians(b->bulletDir));
		float sinang = sin(glm::radians(b->bulletDir));

		b->bulletPos.x +=  cosang * 30;
		b->bulletPos.y +=  sinang * 30;


		b->bulletBox.SetPosition(b->bulletPos.x + 50, b->bulletPos.y + 50);
	}



	//direction++;
	
}

void MachineGun::Upgrade()
{
	if (baseNumber < 3)
	{
		baseNumber++;
		damage = damage + 5;
		fireRate = fireRate - 3;
		base.SetTextureCell(22-baseNumber, 7);
	}
}


	

void MachineGun::shoot()
{

	bullets.push_back(new Bullet);
	
	bullets[bulletcount]->bullet.SetTexture("TileSheet");
	bullets[bulletcount]->bullet.SetSpriteDimension(100, 100);
	bullets[bulletcount]->bullet.SetTextureDimension(23, 13, 64, 64);
	bullets[bulletcount]->bullet.SetTextureCell(19, 11);

	bullets[bulletcount]->bulletBox.SetRadius(5);

	bullets[bulletcount]->bulletPos = position;

	bullets[bulletcount]->bulletDir = direction - 90;
	

	bulletcount++;


}
