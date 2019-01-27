#include "Level_1.h"
#include <gtx\vector_angle.hpp>


Level_1::Level_1()
{



	firstenemy = true;


	// puts the route into the soldiers route
	spawn = glm::vec2(-50, 250);
	goal = glm::vec2(-50, 850);

	Route.push(waypoint1);
	Route.push(waypoint2);
	Route.push(waypoint3);
	Route.push(waypoint4);
	Route.push(waypoint5);
	Route.push(waypoint6);
	Route.push(waypoint7);
	Route.push(waypoint8);

	
	// creates the 7 turrets available in the level
	for (int i = 0; i < 7; i++)
	{
		TurretLocations.push_back(new TurretLocation);
	}

	// sets the dimensions of the turret location boxes
	for (auto t : TurretLocations)
	{
		t->LocationBox.SetDimension(100, 100);
	}
	
	// sets the positions of the turrets and the turret boxes
	TurretLocations[0]->Position = glm::vec2(400,100);
	TurretLocations[0]->LocationBox.SetPosition(400,100);

	TurretLocations[1]->Position = glm::vec2(200, 400);
	TurretLocations[1]->LocationBox.SetPosition(200, 400);

	TurretLocations[2]->Position = glm::vec2(500, 700);
	TurretLocations[2]->LocationBox.SetPosition(500, 700);

	TurretLocations[3]->Position = glm::vec2(1100, 200);
	TurretLocations[3]->LocationBox.SetPosition(1100, 200);

	TurretLocations[4]->Position = glm::vec2(1100, 600);
	TurretLocations[4]->LocationBox.SetPosition(1100, 600);

	TurretLocations[5]->Position = glm::vec2(1500, 600);
	TurretLocations[5]->LocationBox.SetPosition(1500, 600);

	TurretLocations[6]->Position = glm::vec2(1300, 900);
	TurretLocations[6]->LocationBox.SetPosition(1300, 900);
	
	// adds the sprites for the map
	for (int i = 0; i < 14; i++)
	{
		MapChunks.push_back(new Sprite);
	}

	// sets up the sprites for the map
	for (auto it = MapChunks.begin(); it != MapChunks.end(); it++)
	{
		(*it)->SetTexture("TileSheet");
		(*it)->SetSpriteDimension(100, 100);
		(*it)->SetTextureDimension(23, 13, 64, 64);
	}

	MapChunks[0]->SetTextureCell(5, 0);
	MapChunks[1]->SetTextureCell(6, 0);
	MapChunks[2]->SetTextureCell(7, 0);
	MapChunks[3]->SetTextureCell(5, 1);
	MapChunks[4]->SetTextureCell(6, 1);
	MapChunks[5]->SetTextureCell(7, 1);
	MapChunks[6]->SetTextureCell(5, 2);
	MapChunks[7]->SetTextureCell(6, 2);
	MapChunks[8]->SetTextureCell(7, 2);
	MapChunks[9]->SetTextureCell(21, 4);
	MapChunks[10]->SetTextureCell(8, 0);
	MapChunks[11]->SetTextureCell(9, 0);
	MapChunks[12]->SetTextureCell(8, 1);
	MapChunks[13]->SetTextureCell(9, 1);
	
	// adds the rock, plants and craters to the map
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 20; j++) {
			int RanNUM = rand() % 10;
			if (MapPlan[i][j] == 4 && RanNUM == 0)
			{
				Rocks.push_back(new Rock);
				Rocks[rockCount]->SetPosition(glm::vec2(j * 100, i * 100));
				rockCount++;
			}

			else if (MapPlan[i][j] == 4 && RanNUM == 1)
			{
				Plants.push_back(new Plant);
				Plants[plantCount]->SetPosition(glm::vec2(j * 100, i * 100));
				plantCount++;
			}

			else if ((MapPlan[i][j] == 1 || MapPlan[i][j] == 3 || MapPlan[i][j] == 5 || MapPlan[i][j] == 7 ) && (RanNUM == 2 || RanNUM == 3))
			{
				Craters.push_back(new Crater);
				Craters[craterCount]->SetPosition(glm::vec2(j * 100, i * 100));
				craterCount++;
			}

		}

	
}


Level_1::~Level_1()
{
}

void Level_1::Draw()
{
	
	// draws the map
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 20; j++) {

			if (MapPlan[i][j] == 0)
			{
				MapChunks[0]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 1)
			{
				MapChunks[1]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 2)
			{
				MapChunks[2]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 3)
			{
				MapChunks[3]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 4)
			{
				MapChunks[4]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 5)
			{
				MapChunks[5]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 6)
			{
				MapChunks[6]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 7)
			{
				MapChunks[7]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 8)
			{
				MapChunks[8]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 9)
			{
				MapChunks[9]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 10)
			{
				MapChunks[10]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 11)
			{
				MapChunks[11]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 12)
			{
				MapChunks[12]->Draw((j * 100), (i * 100));
			}
			else if (MapPlan[i][j] == 13)
			{
				MapChunks[13]->Draw((j * 100), (i * 100));
			}
			

			
			
		}

	// draws all rocks, plants and craters
	for (auto it = Rocks.begin(); it != Rocks.end(); it++)
	{
		(*it)->Render();
	}
	for (auto it = Plants.begin(); it != Plants.end(); it++)
	{
		(*it)->Render();
	}
	for (auto it = Craters.begin(); it != Craters.end(); it++)
	{
		(*it)->Render();
	}

	// draws all the soldiers and towers
	if (soldiers.size() > 0)
	{
		for (auto s : soldiers)
		{
			s->Update();
			s->Render();
		}
	}

	for (auto t : Towers)
	{
		t->Update();
		t->Draw();
	}
	


	
}

void Level_1::Update()
{
	keys = TheInput::Instance()->GetKeyStates();
	//checks to see if a new wave has been started
	if (waveEnded)
	{
		if (keys[SDL_SCANCODE_SPACE])
		{
			wave++;
		
			waveEnded = false;
		}
	}

	// chekcs to see if the towers have been placed and creates them if so
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[0]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN && player.getMoney() >= 50 && click)
	{
		if (!built0)
		{
			Towers.push_back(new MachineGun(TurretLocations[0]->Position));
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[0]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built0 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);

		}
		else if (built0)
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[0]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[1]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN  && player.getMoney() >= 50 && click)
	{
		if (!built1)
		{
			Towers.push_back(new MachineGun(TurretLocations[1]->Position));
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[1]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built1 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);
		}
		else if (built1)
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[1]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[2]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN  && player.getMoney() >= 50 && click)
	{
		if (!built2)
		{
			Towers.push_back(new MachineGun);
			Towers[towercount]->SetPosition(TurretLocations[2]->Position);
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[2]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built2 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);
		}
		else if (built2 )
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[2]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[3]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN  && player.getMoney() >= 50 && click)
	{
		if (!built3)
		{
			Towers.push_back(new MachineGun);
			Towers[towercount]->SetPosition(TurretLocations[3]->Position);
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[3]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built3 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);
		}
		else if (built3 )
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[3]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[4]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN  && player.getMoney() >= 50 && click)
	{
		if (!built4)
		{
			Towers.push_back(new MachineGun);
			Towers[towercount]->SetPosition(TurretLocations[4]->Position);
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[4]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built4 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);
		}
		else if (built4 )
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[4]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[5]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN  && player.getMoney() >= 50 && click)
	{
		if (!built5)
		{
			Towers.push_back(new MachineGun);
			Towers[towercount]->SetPosition(TurretLocations[5]->Position);
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[5]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built5 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);
		}
		else if (built5)
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[5]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	if (TheInput::Instance()->IsMouseColliding(TurretLocations[6]->LocationBox) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN  && player.getMoney() >= 50 && click)
	{
		if (!built6)
		{
			Towers.push_back(new MachineGun);
			Towers[towercount]->SetPosition(TurretLocations[6]->Position);
			Towers[towercount]->attackRadius.SetPosition(TurretLocations[6]->Position.x + 50, TurretLocations[0]->Position.y + 50);
			built6 = true;
			towercount++;
			player.setMoney(player.getMoney() - 50);

		}
		else if (built6)
		{
			for (auto t : Towers)
			{
				if (t->GetPosition() == TurretLocations[6]->Position && t->GetBaseNumber() < 3 && player.getMoney() >= (t->GetBaseNumber() + 1) * 100)
				{
					t->Upgrade();
					player.setMoney(player.getMoney() - (t->GetBaseNumber()) * 100);
				}
			}
		}
		click = false;
	}
	
	if (clickwait > 50)
	{
		click = true;
		clickwait = 0;
	}

	clickwait++;

	if (!waveEnded)
	{
		// creates the wave full of enemies and checks to see if they are dying
		if (enemycount < wave * 5)
		{
			if (wait > 50)
			{
				soldiers.push_back(new Soldier);
				soldiers[soldiers.size() - 1]->Create(spawn, goal, Route, enemycolour);
				soldiers[soldiers.size() - 1]->SetHealth(wave*wave);
				enemycount++;
				wait = 0;
			}
			wait++;
		}


		if (!soldiers.empty())
		{
			for (auto s : soldiers)
			{
				if (s->Survived())
				{
					soldiers.erase(find(soldiers.begin(), soldiers.end(), s));
					player.setLives(player.getLives() - 1);
					delete s;
				}
				if (!s->IsAlive())
				{
					soldiers.erase(find(soldiers.begin(), soldiers.end(), s));
					player.setMoney(player.getMoney() + 5);
					delete s;
				}
			}

		}
	}
	else 
	{

	}
	
	// chekcs toi see uf the wave has ended
	if ((soldiers.empty())&&(enemycount == wave * 5))
	{
		waveEnded = true;
		enemycount = 0;
	}

	if (enemycolour < 17)
	{
		if (wave > upgradecount)
		{
			enemycolour++;
			upgradecount += 10;
		}
	}



	/// WORKING PROGRESS FOR TURRETS AIMING
	if ((Towers.size() > 0) && (soldiers.size() > 0))
	{
		for (auto t : Towers)
		{
			for (auto s : soldiers)
			{
				if (s->sphere.IsColliding(t->attackRadius))
				{
					

					if (firstenemy)
					{
						glm::vec2 norm = glm::normalize(glm::vec2((s->GetPosition().x + 50) - (t->GetPosition().x + 50), (s->GetPosition().y + 50) - (t->GetPosition().y + 50)));
						t->SetDirection(glm::degrees((atan2(norm.y, norm.x))) + 90);
						firstenemy = false;
					}
						
					if (t->GetFireCount() > t->GetFireRate())
					{
						
						t->shoot();
						t->SetFireCount(0);
						
					}
					
				}
			}
			t->SetFireCount(t->GetFireCount()+1);
			firstenemy = true;
		}

		
	}

	for (auto t : Towers)
	{
		for (auto s : soldiers)
		{
			for (auto b : t->bullets)
			{
				if (b->bulletBox.IsColliding(s->sphere))
				{

					s->hit(t->GetDamage());
					//s->SetAlive(false);
					

					t->bullets.erase(find(t->bullets.begin(), t->bullets.end(), b));
					delete b;
					t->SetBulletCount(t->GetBulletCount()-1);

				}
			}
		}
	}








}
