#include "ScoresState.h"
#include <algorithm>



ScoresState::ScoresState(GameState* previousState) : GameState(previousState)
{
	isActive = true;
	isAlive = true;

	background.create();

	MenuPos = glm::vec2(460, 900);
	QuitPos = glm::vec2(1200, 900);

	title.SetFont("font");
	title.SetText("HIGH SCORES");
	title.SetColor(0, 0, 0);
	title.SetSize(1040, 200);

	fstream scores;
	scores.open("Data_Files\\HighScores.dat", ios_base::in | ios_base::ate | ios_base::binary);

	if (!scores)
	{
		highscores.push_back(new Text);
		highscores[0]->SetFont("font");
		highscores[0]->SetText("There are no high scores!");
		highscores[0]->SetColor(0, 0, 0);
		highscores[0]->SetSize(900, 80);
	}
	else
	{

		int fileSize = scores.tellg();
		int dataSize = sizeof(Score);
		int entrysize = fileSize / dataSize;

		scores.seekg(0);

		for (int i = 0; i < entrysize; i++)
		{
			HighScores.push_back(new Score);
			scores.read((char*)HighScores[i], dataSize);
		}
		sort(HighScores.begin(), HighScores.end(), customMore);

		if (entrysize < 5)
		{
			for (int i = 0; i < entrysize; i++)
			{

				string temp = HighScores[i]->name + " lasted " + to_string(HighScores[i]->score) + " wave's'";
				highscores.push_back(new Text);
				highscores[i]->SetFont("font");
				highscores[i]->SetText(temp);
				highscores[i]->SetColor(0, 0, 0);
				highscores[i]->SetSize(900, 80);
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
			
				string temp = HighScores[i]->name + " lasted " + to_string(HighScores[i]->score) + " wave's'";
				highscores.push_back(new Text);
				highscores[i]->SetFont("font");
				highscores[i]->SetText(temp);
				highscores[i]->SetColor(0, 0, 0);
				highscores[i]->SetSize(900, 80);
			}
		}
					
	}
	scores.close();

	

	

	Menu.text.SetFont("font");
	Menu.text.SetText("MAIN MENU");
	Menu.text.SetColor(0, 0, 0);
	Menu.text.SetSize(360, 100);

	Menu.box.SetDimension(360, 100);
	Menu.box.SetPosition(MenuPos.x, MenuPos.y);

	Quit.text.SetFont("font");
	Quit.text.SetText("QUIT");
	Quit.text.SetColor(0, 0, 0);
	Quit.text.SetSize(160, 100);

	Quit.box.SetDimension(320, 100);
	Quit.box.SetPosition(QuitPos.x, QuitPos.y);
}


ScoresState::~ScoresState()
{
	//delete background;
	background.Destroy();
}

bool ScoresState::Draw()
{
	background.Render();
	title.Draw(440, 80);
	Menu.text.Draw(MenuPos.x, MenuPos.y);
	Quit.text.Draw(QuitPos.x, QuitPos.y);
	int scoreY = 300;
	for (auto s : highscores)
	{
		s->Draw(510, scoreY);
		scoreY += 125;
	}
	return false;
}

bool ScoresState::Update()
{
	Menu.text.SetColor(0, 0, 0);
	Quit.text.SetColor(0, 0, 0);


	if (TheInput::Instance()->IsMouseColliding(Menu.box))
	{
		Menu.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(Quit.box))
	{
		Quit.text.SetColor(255, 0, 0);
	}
	if (TheInput::Instance()->IsMouseColliding(Menu.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		isActive = isAlive = false;
		PreviousState->IsActive() = true;
	}
	else if (TheInput::Instance()->IsMouseColliding(Quit.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		isActive = isAlive = false;
		PreviousState->IsAlive() = false;
	}


	return false;
}

bool ScoresState::OnEnter()
{
	return false;
}

bool ScoresState::OnExit()
{
	return false;
}
