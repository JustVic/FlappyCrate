#ifndef gamestate_h
#define gamestate_h

//#include <functional>
#include "gameengine.h"

class GameState
{
	private:

    public:
		//GameState();
		//~GameState();

		virtual void HandleEvents(GameEngine* game) = 0;

		//virtual void Pause();
		//virtual void Resume();

		virtual void Update(RenderWindow& window) = 0;

		virtual void Draw(RenderWindow& window) = 0;

};

#endif
