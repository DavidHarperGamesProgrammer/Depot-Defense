 #include "Player.h"



Player::Player()
{
	
}


Player::~Player()
{
	fstream Scores;
	if (!Scores.is_open())
	{
		Scores.close();
		Scores.open("Data_Files\\HighScores.dat", ios_base::out | ios_base::app | ios_base::binary);
	}
	else
	{
		cout << "file exists" << endl;
	}
	Scores.write((char*)&score, sizeof(PlayerScore));

	Scores.close();
	//delete background;
	background.Destroy();
}

void Player::Init()
{
	lives = 20;
	money = 50;

	background.create();

	Lives.SetFont("font");
	Lives.SetText("Lives: " + (to_string(lives)));
	Lives.SetColor(0, 0, 0);
	Lives.SetSize(200, 100);

	Money.SetFont("font");
	Money.SetText("Money: " + (to_string(money)));
	Money.SetColor(0, 0, 0);
	Money.SetSize(200, 100);

	name.SetFont("font");
	name.SetText("name");
	name.SetColor(0, 0, 0);
	name.SetSize(400, 200);

	Instructions1.SetFont("font");
	Instructions1.SetText("ENTER YOUR NAME");
	Instructions1.SetColor(0, 0, 0);
	Instructions1.SetSize(600, 200);

	Instructions2.SetFont("font");
	Instructions2.SetText("PRESS ENTER TO CONTINUE");
	Instructions2.SetColor(0, 0, 0);
	Instructions2.SetSize(920, 200);

	score.Name = "";

	while (!nameInput)
	{
		background.PlayMusic();
		//update 
		Sleep(100);
		const Uint8* keys = nullptr;
		keys = TheInput::Instance()->GetKeyStates();
		TheScreen::Instance()->Update();
		TheInput::Instance()->SetTextInput(true);
		TheInput::Instance()->Update();
		score.Name = TheInput::Instance()->GetText();
		name.SetText(score.Name);
		if (keys[SDL_SCANCODE_RETURN])
		{
			nameInput = true;
			TheInput::Instance()->SetTextInput(false);
		}

		if (keys[SDL_SCANCODE_BACKSPACE])
		{
			TheInput::Instance()->PopText();
		}

		// Draw
		background.Render();
		name.Draw(760, 440);
		Instructions1.Draw(660, 100);
		Instructions2.Draw(500, 780);
		TheScreen::Instance()->Draw();
	}
	background.Stop();

}

void Player::Update()
{
	Lives.SetText("Lives: " + (to_string(lives)));
	Money.SetText("Money: " + (to_string(money)));
}

void Player::Render()
{
	Lives.Draw(1700, 50);
	Money.Draw(1700, 200);

}
