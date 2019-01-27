#include "Game.h"





Game::Game()
{
}


bool Game::Init(string Name, int Width, int Height)
{
	/// INITIALIZATION //////////////////////////////////////////////////////////////////////
	//initialise game screen and background rendering color
	TheScreen::Instance()->Initialize(Name.c_str(), Width, Height, false);
	TheScreen::Instance()->SetClearColor(100, 149, 237);

	//initialize audio and textures
	TheAudio::Instance()->Initialize();
	TheTexture::Instance()->Initialize();

	// Load Texture tilesheet for all textures
	TheTexture::Instance()->LoadTextureFromFile("Assets\\Sprites\\tilesheet.png", "TileSheet");

	// Load font for the game
	TheTexture::Instance()->LoadFontFromFile("Assets\\Fonts\\Bombardment.ttf", 200, "font");
	
	ET.SetFont("font");
	ET.SetText(to_string(elapsedTime));
	ET.SetColor(0, 0, 0);
	ET.SetSize(100, 50);

	

	// seeding rand with time to get random numbers
	srand(time(NULL));

	addState(new MenuState(nullptr));

	return false;
}

bool Game::Run()
{
	//main game loop!
	while (!endGame)
	{
		while (States.front()->IsActive())
		{
			int startTime = GetTotal();
			/// UPDATE ///////////////////////////////////////////////////////////////////////////
			//update screen by clearing SDL frame buffer
			TheScreen::Instance()->Update();

			//update input handling by listening for input events
			TheInput::Instance()->Update();
					
			// calling update and draw of the current state
			
			States.front()->Update();
			States.front()->Draw();
			
			ET.SetText(to_string(elapsedTime));
			//ET.Draw(1750, 50);
			TheScreen::Instance()->Draw();
			elapsedTime =  GetTotal()-startTime;
		}
		if (!States.front()->IsAlive())
		{
			removeState();
		}
		if (States.empty())
		{
			endGame = true;
		}
		
	}
	return false;
}

void Game::Shutdown()
{
	// adds the time that the player was in the game to the PlayerTimes.txt file
	if (!Times.is_open())
	{
		Times.close();
		Times.open("Data_Files\\PlayerTimes.txt", ios_base::out | ios_base::app);
	}
	else
	{
		cout << "file exists" << endl;
	}
	Times << "player was in the game for " << TheGame::Instance()->GetTotal()/1000 << " seconds." << endl;
	Times.close();

	// deletes all texture data
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::ALL_DATA);

	// deletes all audio data
	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);
	TheAudio::Instance()->UnloadFromMemory(AudioManager::SFX_AUDIO, AudioManager::ALL_AUDIO);
	TheAudio::Instance()->UnloadFromMemory(AudioManager::VOICE_AUDIO, AudioManager::ALL_AUDIO);

	// close down audio 
	TheAudio::Instance()->ShutDown();

	// close down textures
	TheTexture::Instance()->ShutDown();

	// close down game screen 
	TheScreen::Instance()->ShutDown();
}

void Game::addState(GameState * state)
{
	States.push_front(state);
}

void Game::changeState(GameState * state)
{
	States.push_back(state);
}

void Game::removeState()
{
	delete States.front();
	States.pop_front();
}