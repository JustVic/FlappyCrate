#include "renderer.h"

RenderManager::RenderManager()
{
	window.create(sf::VideoMode(640, 480), "Gameu"); 

	heroTexture.loadFromFile("images/wolf.png");
	
	heroSprite.setTexture(heroTexture);
	
	heroSprite.setTextureRect(sf::IntRect(0,0,155,86));

	heroSprite.setPosition(50, 25);
}

void RenderManager::DrawTexture()
{
	window.clear();

	window.draw(heroSprite);

	window.display();
}

void RenderManager::Update()
{
	sf::Event event;
	
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}	
}

void RenderManager::Delay()
{
	
}

void RenderManager::Cleanup()
{
}
