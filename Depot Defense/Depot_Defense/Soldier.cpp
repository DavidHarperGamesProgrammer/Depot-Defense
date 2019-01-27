#include "Soldier.h"



Soldier::Soldier()
{
	
}


Soldier::~Soldier()
{

}

void Soldier::Update()
{

	// chekc to see what direct and applies roattion 
	switch(dir)
	{
	case UP:
		direction = 270;
		break;
	case DOWN:
		direction = 90;
		break;
	case LEFT:
		direction = 180;
		break;
	case RIGHT:
		direction = 0;
		break;
	default:
		break;
	}

	// checks to see where it shpould be walking
	if (position.x < Route.front().x)
	{
		position.x = position.x + speed;
		dir = RIGHT;
	}
	else if (position.x > Route.front().x)
	{
		position.x = position.x - speed;
		dir = LEFT;
	}

	if (position.y < Route.front().y)
	{
		position.y = position.y + speed;
		dir = DOWN;
	}
	else if (position.y > Route.front().y)
	{
		position.y = position.y - speed;
		dir = UP;
	}

	// checks if its at a waypoint and pops that waypoint off the queue
	if ((position.x == Route.front().x) && (position.y == Route.front().y))
	{
		Route.pop();
	}

	if (Route.empty())
	{
		survived = true;
		/// take away a player life
	}

	if (health <= 0)
	{
		isAlive = false;
	}

	sphere.SetPosition(position.x + 50, position.y + 50);

}

void Soldier::Render()
{
	sprite.Draw(position.x, position.y, direction);
}

void Soldier::Create(glm::vec2 spawn, glm::vec2 goal, queue<glm::vec2> route, int colour)
{
	// sets all properties for the soldier
	sprite.SetTexture("TileSheet");
	sprite.SetSpriteDimension(100, 100);
	sprite.SetTextureDimension(23, 13, 64, 64);
	sprite.SetTextureCell(colour, 10);

	sphere.SetRadius(50);
	sphere.SetPosition(0, 0);

	health = 10;
	speed = 4;
	isAlive = true;
	survived = false;
	Spawn = spawn;
	Goal = goal;
	Route = route;
	Route.push(Goal);
	dir = RIGHT;

	position = Spawn;
}
