#include "Credits.h"



Credits::Credits()
{
	StartPos = glm::vec2(1230, 900);
	MainmenuPos = glm::vec2(490, 900);

	//background.create();
	// sets all the text on the screen up with positions and fonts aswell as boxes for the buttons
	title.SetFont("font");
	title.SetText("CREDITS");
	title.SetColor(0, 0, 0);
	title.SetSize(560, 200);

	TexCredit.SetFont("font");
	TexCredit.SetText("All Game Art - Kenney");
	TexCredit.SetColor(0, 0, 0);
	TexCredit.SetSize(840, 100);

	FontCredit.SetFont("font");
	FontCredit.SetText("Font - Vladimir Nikolic");
	FontCredit.SetColor(0, 0, 0);
	FontCredit.SetSize(920, 100);

	SoundCredit.SetFont("font");
	SoundCredit.SetText("sounds - freesound");
	SoundCredit.SetColor(0, 0, 0);
	SoundCredit.SetSize(720, 100);


	Start.text.SetFont("font");
	Start.text.SetText("START");
	Start.text.SetColor(0, 0, 0);
	Start.text.SetSize(200, 100);

	Start.box.SetDimension(200, 100);
	Start.box.SetPosition(StartPos.x, StartPos.y);

	Mainmenu.text.SetFont("font");
	Mainmenu.text.SetText("MAIN MENU");
	Mainmenu.text.SetColor(0, 0, 0);
	Mainmenu.text.SetSize(360, 100);

	Mainmenu.box.SetDimension(360, 100);
	Mainmenu.box.SetPosition(MainmenuPos.x, MainmenuPos.y);
}


Credits::~Credits()
{
	//delete background;
	//background.Destroy();
}

void Credits::Draw()
{
	// draws everything on the menu in the correct order
//	background.Render();
	title.Draw(680, 80);
	Start.text.Draw(StartPos.x, StartPos.y);
	Mainmenu.text.Draw(MainmenuPos.x, MainmenuPos.y);
	TexCredit.Draw(540, 320);
	FontCredit.Draw(500, 470);
	SoundCredit.Draw(580, 620);
}

void Credits::Update()
{
	Start.text.SetColor(0, 0, 0);
	Mainmenu.text.SetColor(0, 0, 0);

	// checks mouse position to change colour of the text
	if (TheInput::Instance()->IsMouseColliding(Start.box))
	{
		Start.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(Mainmenu.box))
	{
		Mainmenu.text.SetColor(255, 0, 0);
	}

	// chekcs to see if the button has been pressed
	if (TheInput::Instance()->IsMouseColliding(Mainmenu.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		mainmenu = true;
	}
	else if (TheInput::Instance()->IsMouseColliding(Start.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		start = true;
	}
	
}
