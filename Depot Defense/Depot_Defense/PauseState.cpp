#include "PauseState.h"



PauseState::PauseState(GameState* previousState) : GameState(previousState)
{
	isActive = true;
	isAlive = true;

	background.create();

	MenuPos = glm::vec2(460, 720);
	ContinuePos = glm::vec2(1100, 720);

	title.SetFont("font");
	title.SetText("DEPOT DEFENSE");
	title.SetColor(0, 0, 0);
	title.SetSize(1040, 200);

	pause.SetFont("font");
	pause.SetText("PAUSED");
	pause.SetColor(0, 0, 0);
	pause.SetSize(240, 100);

	Menu.text.SetFont("font");
	Menu.text.SetText("MAIN MENU");
	Menu.text.SetColor(0, 0, 0);
	Menu.text.SetSize(360, 100);

	Menu.box.SetDimension(360, 100);
	Menu.box.SetPosition(MenuPos.x, MenuPos.y);

	Continue.text.SetFont("font");
	Continue.text.SetText("CONTINUE");
	Continue.text.SetColor(0, 0, 0);
	Continue.text.SetSize(320, 100);

	Continue.box.SetDimension(320, 100);
	Continue.box.SetPosition(ContinuePos.x, ContinuePos.y);



}


PauseState::~PauseState()
{
	//delete background;
	background.Destroy();
}

bool PauseState::Draw()
{
	background.Render();
	title.Draw(440, 80);
	pause.Draw(840, 490);
	Menu.text.Draw(MenuPos.x, MenuPos.y);
	Continue.text.Draw(ContinuePos.x, ContinuePos.y);
	return false;
}

bool PauseState::Update()
{
	background.PlayMusic();
	Menu.text.SetColor(0, 0, 0);
	Continue.text.SetColor(0, 0, 0);

	//if escape key is pressed flag game to end
	if (TheInput::Instance()->IsMouseColliding(Menu.box))
	{
		Menu.text.SetColor(255, 0, 0);
	}
	else if (TheInput::Instance()->IsMouseColliding(Continue.box))
	{
		Continue.text.SetColor(255, 0, 0);
	}
	if (TheInput::Instance()->IsMouseColliding(Menu.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		isActive = isAlive = false;
		PreviousState->IsAlive() = false;
		TheGame::Instance()->changeState(new MenuState(nullptr));

	}
	else if (TheInput::Instance()->IsMouseColliding(Continue.box) && TheInput::Instance()->GetLeftButtonState() == TheInput::Instance()->DOWN)
	{
		isActive = isAlive = false;
		PreviousState->IsActive() = true;
	}


	return false;
}

bool PauseState::OnEnter()
{
	return false;
}

bool PauseState::OnExit()
{
	return false;
}
