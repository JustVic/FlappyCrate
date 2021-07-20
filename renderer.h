
//#include <stdio.h>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;

class RenderManager
{
	private:
		//SDL_Renderer* renderer;
		int width;
		int height;
		int cellWidth;
		
		Texture herotexture;
        Sprite herosprite;
        RenderWindow window;

	public:
		RenderManager();

		void Cleanup();

		void Update();

		void Delay();

		//SDL_Renderer* GetSDLRenderer();

		//kiss_window* GetWindow(){ return &window1; };

		int GetWidth(){ return width; };

		int GetHeight(){ return height; };

		int GetCellWidth(){ return cellWidth; };

		//std::shared_ptr<SDL_Texture> createTexture(std::string image);

		//void DrawSprite(int x, int y, int width, int height, SDL_Surface* sprite);

		void DrawTexture();


};

