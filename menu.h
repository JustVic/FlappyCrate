#ifndef menu_h
#define menu_h

#include "gamestate.h"
#include <SFML/Graphics.hpp>

class Menu : public GameState
{
	private:
		Texture herotexture;
		
		Sprite herosprite;
		
		sf::Text text;
		
		sf::Font font;


	public:
		Menu(GameEngine* game);

		void Update(RenderWindow& window);

		void HandleEvents(GameEngine* game);

		void Draw(RenderWindow& window);
};

#endif
