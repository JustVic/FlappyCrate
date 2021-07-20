#ifndef singleplayer_h
#define singleplayer_h

#include "gamestate.h"
#include <vector>
#include <list>
#include <deque>
#include <SFML/Graphics.hpp>

using namespace sf;

class Singleplayer : public GameState
{
	private:
		Texture herotexture;
        Sprite herosprite;

        std::vector<Sprite> obstacleSprites;
        std::vector<Texture> obstacleTextures;
        sf::Text gameOverText;
        sf::Font font;
        int direction;
        bool gameOverFlag;


	public:
		Singleplayer(GameEngine* game);
		
		bool Collision();
		
		void RemoveOldAndAddNewObstacle();

		void Update(RenderWindow& window);

		void HandleEvents(GameEngine* game);

		void Draw(RenderWindow& window);
};

#endif
