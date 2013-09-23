//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "gameobj.h"

const int IScreenWidth = 1280;
const int IScreenHeight = 780;

int main( int argc, char* argv[] )
{	Initialise(1280, 780, false );
	initGame();
	do 
	{
	
		ClearScreen();

		updateGame();

		drawGame();
	} while ( FrameworkUpdate() == false );
	destroyGame();
	Shutdown();
	return 0;
}

