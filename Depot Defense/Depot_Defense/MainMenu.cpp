#include "MainMenu.h"



MainMenu::MainMenu()
{

	//background.create();
	// sets all positions
	StartPos = glm::vec2(860, 360);
	InstructionsPos = glm::vec2(720, 480);
	HighScoresPos = glm::vec2(740, 600);
	CreditsPos = glm::vec2(820, 720);	
	QuitPos = glm::vec2(880, 840);
	
	// stes the text and bounding boxes on the menu
	title.SetFont("font");
	title.SetText("DEPOT DEFENSE");
	title.SetColor(0, 0, 0);
	title.SetSize(1040, 200);
	
	Start.text.SetFont("font");
	Start.text.SetText("START");
	Start.text.SetColor(0,0,0);
	Start.text.SetSize(200, 100);

	Start.box.SetDimension(200, 100);
	Start.box.SetPosition(StartPos.x, StartPos.y);
	
	Instructions.text.SetFont("font");
	Instructions.text.SetText("INSTRUCTIONS");
	Instructions.text.SetColor(0, 0, 0);
	Instructions.text.SetSize(480, 100);

	Instructions.box.SetDimension(480, 100);
	Instructions.box.SetPosition(InstructionsPos.x, InstructionsPos.y);
	
	Credits.text.SetFont("font");
	Credits.text.SetText("CREDITS");
	Credits.text.SetColor(0, 0, 0);
	Credits.text.SetSize(280, 100);

	Credits.box.SetDimension(280, 100);
	Credits.box.SetPosition(CreditsPos.x, CreditsPos.y);
	
	Quit.text.SetFont("font");
	Quit.text.SetText("QUIT");
	Quit.text.SetColor(0, 0, 0);
	Quit.text.SetSize(160, 100);

	Quit.box.SetDimension(160, 100);
	Quit.box.SetPosition(QuitPos.x, QuitPos.y);

	HighScores.text.SetFont("font");
	HighScores.text.SetText("HIGH SCORES");
	HighScores.text.SetColor(0, 0, 0);
	HighScores.text.SetSize(440, 100);

	HighScores.box.SetDimension(480, 100);
	HighScores.box.SetPosition(HighScoresPos.x, HighScoresPos.y);
}


MainMenu::~MainMenu()
{
	//delete background
	//background.Destroy();
}

void MainMenu::Draw()
{
	//draws all buttons and background
	//background.Render();
	title.Draw(440, 80);
	Start.text.Draw(StartPos.x, StartPos.y);
	Instructions.text.Draw(InstructionsPos.x, InstructionsPos.y);
	Credits.text.Draw(CreditsPos.x, CreditsPos.y);
	Quit.text.Draw(QuitPos.x, QuitPos.y);
	HighScores.text.Draw(HighScoresPos.x, HighScoresPos.y);
}

void MainMenu::Update()
{
	

	Start.text.SetColor(0, 0, 0);
	Instructions.text.SetColor(0, 0, 0);
	Credits.text.SetColor(0, 0, 0);
	Quit.text.SetColor(0, 0, 0);
	HighScores.text.SetColor(0, 0, 0);

	// checks mouse position to change the colour of the text on the menu
	if (TheInput::Instance()->IsMouseColliding(Start.box))
	{
		Start.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(Instructions.box))
	{
		Instructions.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(Credits.box))
	{
		Credits.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(Quit.box))
	{
		Quit.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(HighScores.box))
	{
		HighScores.text.SetColor(255, 0, 0);
	}
	else
	{}

	// checks to see if a button has been clicked
	if (TheInput::Instance()->IsMouseColliding(Instructions.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		instructions = true;
	}
	else if (TheInput::Instance()->IsMouseColliding(Credits.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		credits = true;
	}
	else if (TheInput::Instance()->IsMouseColliding(Start.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		start = true;
	}
	else if (TheInput::Instance()->IsMouseColliding(Quit.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		quitting = true;
	}
	else if (TheInput::Instance()->IsMouseColliding(HighScores.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		scores = true;
	}
	

}
