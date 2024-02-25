#include "intro.h"

Intro::Intro(const GameEngine* game)
{

	if (!font.loadFromFile("data/kiss_font.ttf"))
	{
		//error
	}
	
	// select the font
	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("Press SPACE Key");
	
	text.setCharacterSize(24);
	
	text.setFillColor(sf::Color::Red);
	
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	
	FloatRect bounds = text.getLocalBounds();
	
	text.setPosition(300-bounds.width/2, 300-bounds.height/2);
	
	heroTexture.loadFromFile("data/images/background.png");

	heroSprite.setTexture(heroTexture);
	
	heroSprite.setTextureRect(sf::IntRect(0,0,640,640));
	
	heroSprite.setPosition(0, text.getPosition().y+bounds.height*2);

}

void Intro::Update(RenderWindow& window)
{

}

void Intro::HandleEvents(GameEngine* game)
{
	if (Keyboard::isKeyPressed(Keyboard::Space)) { game->ToSingleplayer(); }
		
	if (Keyboard::isKeyPressed(Keyboard::Left)) { heroSprite.move(-0.5, 0); }

	if (Keyboard::isKeyPressed(Keyboard::Right)) { heroSprite.move(0.5, 0); }

	if (Keyboard::isKeyPressed(Keyboard::Up)) { heroSprite.move(0, -0.5); }

	if (Keyboard::isKeyPressed(Keyboard::Down)) { heroSprite.move(0, 0.5); }
}

void Intro::Draw(RenderWindow& window)
{
	window.draw(heroSprite);
	window.draw(text);
}


