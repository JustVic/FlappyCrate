#ifndef intro_h
#define intro_h

#include "gamestate.h"
#include <SFML/Graphics.hpp>

class Intro : public GameState
{
	private:
		Texture heroTexture;
		
		Sprite heroSprite;
		
		sf::Text text;
		
		sf::Font font;


	public:
		Intro(const GameEngine* game);

		void Update(RenderWindow& window);

		void HandleEvents(GameEngine* game);

		void Draw(RenderWindow& window);
};

#endif
