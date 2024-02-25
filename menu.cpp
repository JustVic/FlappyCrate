#include "menu.h"

Menu::Menu(GameEngine* game)
{
}

void Menu::Update(RenderWindow& window)
{

}

void Menu::HandleEvents(GameEngine* game)
{	
	if (Keyboard::isKeyPressed(Keyboard::Left)) { herosprite.move(-0.5, 0); }
	
	if (Keyboard::isKeyPressed(Keyboard::Right)) { herosprite.move(0.5, 0); }

	if (Keyboard::isKeyPressed(Keyboard::Up)) { herosprite.move(0, -0.5); }

	if (Keyboard::isKeyPressed(Keyboard::Down)) { herosprite.move(0, 0.5); }
}

void Menu::Draw(RenderWindow& window)
{
		window.draw(text);
		
		window.draw(herosprite);
}
