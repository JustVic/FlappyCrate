#ifndef intro_h
#define intro_h

#include "gamestate.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Intro : public GameState
{
	private:
		Texture herotexture;
        Sprite herosprite;
        sf::Text text;
        sf::Font font;


	public:
		Intro(GameEngine* game);

		void Update(RenderWindow& window);

		void HandleEvents(GameEngine* game);

		void Draw(RenderWindow& window);
};

#endif
