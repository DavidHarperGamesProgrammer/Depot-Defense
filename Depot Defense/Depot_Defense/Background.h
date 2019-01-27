#pragma once

#include "Audio.h"
#include "AudioManager.h"
#include "GameObject.h"
#include "Sprite.h"
#include "TextureManager.h"


class Background : public GameObject
{
public:
	Background();
	virtual ~Background() override;
	
	// Inherited via GameObject
	virtual void Update() override;
	virtual void Render() override;
	void create();
	void Destroy();
	void PlayMusic();
	void Stop();

private:

	Audio music;
	Sprite image;
};

