#include "singleplayer.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Singleplayer::Singleplayer(GameEngine* game)
{
	if (!font.loadFromFile("data/kiss_font.ttf"))
	{
		//error
	}
	
	// select the font
	gameOverText.setFont(font); // font is a sf::Font

	// set the string to display
	gameOverText.setString("GameOver");
	
	gameOverText.setCharacterSize(24);
	
	gameOverText.setFillColor(sf::Color::Red);
	
	gameOverText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	
	FloatRect bounds = gameOverText.getLocalBounds();
	
	gameOverText.setPosition(320-bounds.width/2, 240-bounds.height/2);
	
	heroTexture.loadFromFile("data/images/crate.png");

	heroSprite.setTexture(heroTexture);
	
	heroSprite.setTextureRect(sf::IntRect(0,0,63,63));
	
	heroSprite.setPosition(160, 240);

	direction = 0;
	
	int obstacles_num = 8;
	
    	obstacleTexture.loadFromFile("data/images/quadb.bmp");

	for(int i = 0; i < obstacles_num;)
	{
		int rd = rand()%2;
		
		int a = 0;
		
		if(rd)
			a = 40;
		else
			a = -40;
			
		int y1_pos = 0-90+a;
		
		int y2_pos = 480-256+90+a;
			
		Sprite obstacleSprite;

		obstacleSprite.setTexture(obstacleTexture);

		obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));

		obstacleSprite.setScale(3, 8.53);

		obstacleSprite.setPosition((640+(i*90)), y1_pos);			
		obstacleSprites.push_back(obstacleSprite);
		
		i++;

		obstacleSprite.setTexture(obstacleTexture);
			
		obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));

		obstacleSprite.setScale(3, 8.53);
			
		obstacleSprite.setPosition((640+((i-1)*90)), y2_pos);
			
		obstacleSprites.push_back(obstacleSprite);

		i++;

	}
	gameOverFlag = false;

}

bool Singleplayer::Collision()
{
	sf::Vector2f hposition = heroSprite.getPosition();
	
	FloatRect hbounds = heroSprite.getGlobalBounds();
	
	for(int i = 0; i < obstacleSprites.size(); i++)
	{
		sf::Vector2f oposition = obstacleSprites[i].getPosition();
		
		FloatRect obounds = obstacleSprites[i].getGlobalBounds();

		if(((hposition.y > oposition.y)and(hposition.y < (oposition.y+obounds.height)))or(((hposition.y+hbounds.height) > oposition.y)and((hposition.y+hbounds.height) < (oposition.y+obounds.height))))
		{

			if((hposition.x > oposition.x)and(hposition.x < (oposition.x+obounds.width)))
			{
				return true;
			}
		
			if(((hposition.x+hbounds.width) > oposition.x)and((hposition.x+hbounds.width) < (oposition.x+obounds.width)))
			{
				return true;
			}
		}
	}

	if((hposition.x+hbounds.width > 640)or(hposition.x < 0)or(hposition.y < 0)or(hposition.y+hbounds.height > 480))
		return true;
	
	return false;
}

void Singleplayer::RemoveOldAndAddNewObstacle()
{
	
	for(int i = 0; i < obstacleSprites.size(); i++)
	{
		Sprite obstacleSprite;
		
		sf::Vector2f position = obstacleSprites[i].getPosition();
		
		if(position.x<-90)
		{
			int rd = rand()%2;
			
			int a = 0;
			
			if(rd)
				a = 40;
			else
				a = -40;
			
			int y1_pos = 0-90+a;
			
			int y2_pos = 480-256+90+a;
			
			Sprite obstacleSprite;			
			
			if(i%2)
			{	
				obstacleSprite.setTexture(obstacleTexture);
				
				obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));
				obstacleSprite.setScale(3, 8.53);
				
				obstacleSprite.setPosition(640, y1_pos);
			}
			else
			{
				obstacleSprite.setTexture(obstacleTexture);
				
				obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));
				obstacleSprite.setScale(3, 8.53);
				
				obstacleSprite.setPosition(640, y2_pos);
			}
			
			obstacleSprites.push_back(obstacleSprite);
		}			
	}
	
		
	for(auto it = obstacleSprites.begin(); it!=obstacleSprites.end();)
	{
		sf::Vector2f position = it->getPosition();
		
		if(position.x<-90)
		{
			it = obstacleSprites.erase(it);
		}
		else
			it++;
	}
}

void Singleplayer::Update(RenderWindow& window)
{
	if(!gameOverFlag)
	{
		if(direction == 0)
			heroSprite.move(-1.f, 0.f);
		if(direction == 1)
			heroSprite.move(1.f, 0.f);
			
			
		for(int i = 0; i < obstacleSprites.size(); i++)
		{
			obstacleSprites.at(i).move(-1.f, 0.0);
		}	
		
		RemoveOldAndAddNewObstacle();
	}
		
	heroSprite.move(0.f, +2.f);
	
	if(Collision())
		gameOverFlag = true;
	
}

void Singleplayer::HandleEvents(GameEngine* game)
{

	if(!gameOverFlag)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)) { heroSprite.move(-0.0, -4.0); direction = 0; }
		if (Keyboard::isKeyPressed(Keyboard::Right)) { heroSprite.move(0.0, -4.0);  direction = 1; }
		if (Keyboard::isKeyPressed(Keyboard::Up)) { heroSprite.move(0, -0.5); }
		if (Keyboard::isKeyPressed(Keyboard::Down)) { heroSprite.move(0, 0.5); }
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Escape)) { game->PopState();}
}

void Singleplayer::Draw(RenderWindow& window)
{
		if(gameOverFlag)
			window.draw(gameOverText);
			
		window.draw(heroSprite);
		
		for(int i = 0; i < obstacleSprites.size(); i++)
		{
			window.draw(obstacleSprites[i]);
		}
}
