#include "Instructions.h"



Instructions::Instructions()
{
	StartPos = glm::vec2(1230, 900);
	MainmenuPos = glm::vec2(490, 900);

	//background.create();

	// sets all the text on the screen up with positions and fonts aswell as boxes for the buttons
	title.SetFont("font");
	title.SetText("INSTRUCTIONS");
	title.SetColor(0, 0, 0);
	title.SetSize(960, 200);
                   
	line1.SetFont("font");
	line1.SetText("Defend your depot by placing towers with your "); 
	line1.SetColor(0, 0, 0);
	line1.SetSize(1840,100);

	line2.SetFont("font");
	line2.SetText("mouse. Survive as many waves of eneimes as you");
	line2.SetColor(0, 0, 0);
	line2.SetSize(1840, 100);
	
	line3.SetFont("font");
	line3.SetText("can, pressing space to begin the wave!        ");
	line3.SetColor(0, 0, 0);
	line3.SetSize(1840, 100);

	line4.SetFont("font");
	line4.SetText("Have fun!                                     ");
	line4.SetColor(0, 0, 0);
	line4.SetSize(1840, 100);

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


Instructions::~Instructions()
{
	//delete background;
	//background.Destroy();
}

void Instructions::Draw()
{
	// draws everything on the menu in the correct order
	//background.Render();
	title.Draw(480, 80);
	Start.text.Draw(StartPos.x, StartPos.y);
	Mainmenu.text.Draw(MainmenuPos.x, MainmenuPos.y);
	line1.Draw(40, 320);
	line2.Draw(40, 470);
	line3.Draw(40, 620);
	line4.Draw(40, 770);
}

void Instructions::Update()
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
