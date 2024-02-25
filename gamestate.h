#ifndef gamestate_h
#define gamestate_h

#include "gameengine.h"

class GameState
{
	private:

	public:
		virtual void HandleEvents(GameEngine* game) = 0;

		virtual void Update(RenderWindow& window) = 0;

		virtual void Draw(RenderWindow& window) = 0;

};

#endif
