#include "Background.h"



Background::Background()
{
	
}

void Background::Update()
{
}

void Background::Render()
{
	image.Draw();
}

void Background::create()
{
	TheTexture::Instance()->LoadTextureFromFile("Assets\\Textures\\background.png", "Background Image");

	TheAudio::Instance()->LoadFromFile("Assets\\Audio\\Ambient.ogg", AudioManager::MUSIC_AUDIO, "Background Music");

	// Setting Image Properties
	image.SetTexture("Background Image");
	image.SetSpriteDimension(1920, 1080);
	image.SetTextureDimension(1, 1, 1886, 1061);

	// Setting Music Properties
	music.SetAudio("Background Music", Audio::MUSIC_AUDIO);
	music.SetVolume(100);
	music.Play(Audio::PLAY_ENDLESS);
}

void Background::Destroy()
{
	/*TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Background Image");
	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::CUSTOM_AUDIO, "Background Music");*/
	music.Pause();
}

void Background::PlayMusic()
{
	music.Resume();
}

void Background::Stop()
{
	music.Stop();
}


Background::~Background()
{
	
}
