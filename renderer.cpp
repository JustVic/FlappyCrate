#include "renderer.h"

int draw = 1;

RenderManager::RenderManager()
{
	    //window = game->GetWindow();
    window.create(sf::VideoMode(640, 480), "Gameu"); 

	//int center = game->GetRend()->GetWidth()/2;
	
	herotexture.loadFromFile("images/wolf.png");
herosprite.setTexture(herotexture);
	herosprite.setTextureRect(sf::IntRect(0,0,155,86));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(50, 25);
}

/*std::shared_ptr<SDL_Texture> RenderManager::createTexture(std::string image)
{

    //SDL_Surface* surface = SDL_LoadBMP(image.c_str());
	//std::shared_ptr<SDL_Surface> surface = std::shared_ptr<SDL_Surface>(SDL_LoadBMP(image.c_str()), SDL_FreeSurface);

	//std::shared_ptr<SDL_Texture> texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(this->renderer, surface.get()), SDL_DestroyTexture);

	//SDL_FreeSurface(surface);

	return texture;
}*/

void RenderManager::DrawTexture()
{
	window.clear();
	window.draw(herosprite);
	window.display();
}

void RenderManager::Update()
{

	//running = window.isOpen();
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	
}

void RenderManager::Delay()
{
	//SDL_Delay(2000);
}

void RenderManager::Cleanup()
{
	//kiss_clean(&objects);

	//SDL_Quit();
}
