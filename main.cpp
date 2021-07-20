#include <SFML/Graphics.hpp>
#include "gameengine.h"

using namespace sf;
int main()
{
	GameEngine game;

	bool quit = false;
 
 	if( !game.Init() ){
		printf( "Failed to initialize!\n" );
	}
	else
	{
		while (game.Running())	
		{
			game.HandleEvents();
			game.Draw();
			game.Update();
		}
 	}
 	
 	game.Cleanup();
	return true;
}
