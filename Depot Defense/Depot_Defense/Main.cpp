/*

  All code has been written by Karsten Vermeulen and may be used freely by anyone. It is by no
  means perfect and there is certainly room for improvement in some parts. As a whole, the code
  has been created as part of an engine for the purposes of educating other fellow programmers,
  and anyone else wishing to learn C++ and OOP. Feel free to use, copy, break, update and do as
  you wish with this code - it is there for all!

  UPDATED : February 2017

  -----------------------------------------------------------------------------------------------

- This is the main starting point for the game demo. The main game state is created here and added
  to the main game manager, from where it is run. Change the screen width and height accordingly, 
  and feel free to add more game states.

*/

//include SDL main header file to prevent 
//main lib conflicts in Release mode

#include "Game.h"

//screen width and height values
int screenWidth = 1920;
int screenHeight = 1080;

//variable for name of game demo
std::string gameName = "Depot Defense";

//------------------------------------------------------------------------------------------------------
//main function that processes everything  
//------------------------------------------------------------------------------------------------------
int main(int argc, char* args[])
{
	// initializing game 
	TheGame::Instance()->Init(gameName, screenWidth, screenHeight);

	// running main game
	TheGame::Instance()->Run();

	// shutting down the game
	TheGame::Instance()->Shutdown();
	
	// end application
	return 0;

}