#ifndef singleplayer_h
#define singleplayer_h

#include "gamestate.h"
#include <vector>
#include <list>
#include <deque>
#include <SFML/Graphics.hpp>

class Singleplayer : public GameState
{
	private:
		Texture heroTexture;
        	
		Sprite heroSprite;

        	std::vector<Sprite> obstacleSprites;
        	
		std::vector<Texture> obstacleTextures;
        	
		sf::Text gameOverText;
        	
		sf::Font font;
        	
		int direction;
        	
		bool gameOverFlag;
        
        	Texture obstacleTexture;

	public:
		Singleplayer(GameEngine* game);
		
		bool Collision();
		
		void RemoveOldAndAddNewObstacle();

		void Update(RenderWindow& window);

		void HandleEvents(GameEngine* game);

		void Draw(RenderWindow& window);
};

#endif
