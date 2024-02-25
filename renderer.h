
//#include <stdio.h>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class RenderManager
{
	private:
		int width;
		
		int height;

		int cellWidth;
		
		sf::Texture heroTexture;
        	
		sf::Sprite heroSprite;
        	
		sf::RenderWindow window;

	public:
		RenderManager();

		void Cleanup();

		void Update();

		void Delay();

		int GetWidth(){ return width; };

		int GetHeight(){ return height; };

		int GetCellWidth(){ return cellWidth; };

		void DrawTexture();

};

