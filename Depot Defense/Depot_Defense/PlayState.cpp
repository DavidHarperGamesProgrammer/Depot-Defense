#include "PlayState.h"
#include "PauseState.h"



PlayState::PlayState(GameState* previousState) : GameState(previousState)
{
	isActive = true;
	isAlive = true;
	level1.player.Init();

	TheAudio::Instance()->LoadFromFile("Assets\\Audio\\war.ogg", AudioManager::MUSIC_AUDIO, "WAR");
	

	Layer1.SetAudio("WAR", Audio::MUSIC_AUDIO);
	Layer1.SetVolume(100);
	Layer1.Play(Audio::PLAY_ENDLESS);

	/*TheAudio::Instance()->LoadFromFile("Assets\\Audio\\battle.ogg", AudioManager::MUSIC_AUDIO, "BATTLE");

	Layer2.SetAudio("BATTLE", Audio::MUSIC_AUDIO);
	Layer2.SetVolume(100);
	Layer2.Play(Audio::PLAY_ENDLESS);*/


}


PlayState::~PlayState()
{
	Layer1.Stop();
	Layer2.Stop();
}

bool PlayState::Draw()
{
	//draws all of level 1
	level1.Draw();
	level1.player.Render();
	return false;
}

bool PlayState::Update()
{
	const Uint8* keys = nullptr;
	//read keyboard state
	keys = TheInput::Instance()->GetKeyStates();
	//if escape key is pressed flag game to end
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		isActive = false;
		TheGame::Instance()->addState(new PauseState(this));
	}
	//if game window's top right X is clicked flag game to end
	if (TheInput::Instance()->IsXClicked())
	{
		isAlive = isActive = false;
	}
	if (level1.player.getLives() == 0)
	{
		isActive = isAlive = false;
		TheGame::Instance()->changeState(new MenuState(nullptr));
	}

	//updates all of level 1
	level1.player.setScore(level1.getWave());
	level1.player.Update();
	level1.Update();
	return false;
}

bool PlayState::OnEnter()
{
	return false;
}

bool PlayState::OnExit()
{
	return false;
}
