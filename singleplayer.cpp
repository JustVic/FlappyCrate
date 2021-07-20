#include "singleplayer.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


Singleplayer::Singleplayer(GameEngine* game)
{
    //window = game->GetWindow();
    /*window.create(sf::VideoMode(640, 480), "Game"); */

	//int center = game->GetRend()->GetWidth()/2;

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
	
	
	herotexture.loadFromFile("data/images/crate.png");

	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(sf::IntRect(0,0,63,63));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(160, 240);
	//herosprite.setScale(0.5f, 0.5f);
	
	direction = 0;
	
	int obstacles_num = 8;
	
	for(int i = 0; i < obstacles_num; i++)
	{
		Texture obstacleTexture;
    	obstacleTexture.loadFromFile("data/images/quadb.bmp");
    	obstacleTextures.push_back(obstacleTexture);
	}
	
	for(int i = 0; i < obstacles_num;)
	{
		//int i = 0;
		int rd = rand()%2;
		int a = 0;
		if(rd)
			a = 40;
			else
			a = -40;
			
		int y1_pos = 0-90+a;
		int y2_pos = 480-256+90+a;
			
		Sprite obstacleSprite;

			obstacleSprite.setTexture(obstacleTextures[i]);
			obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));//получили нужный нам прямоугольник с котом
			obstacleSprite.setScale(3, 8.53);
			obstacleSprite.setPosition((640+(i*90)), y1_pos);
			
			
			obstacleSprites.push_back(obstacleSprite);
		i++;

			obstacleSprite.setTexture(obstacleTextures[i]);
			obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));//получили нужный нам прямоугольник с котом
			obstacleSprite.setScale(3, 8.53);
			obstacleSprite.setPosition((640+((i-1)*90)), y2_pos);
			
			obstacleSprites.push_back(obstacleSprite);

		i++;

	}
	gameOverFlag = false;

}

bool Singleplayer::Collision()
{
	sf::Vector2f hposition = herosprite.getPosition();
	FloatRect hbounds = herosprite.getGlobalBounds();
	
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
				obstacleSprite.setTexture(obstacleTextures[i]);
				obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));
				obstacleSprite.setPosition(640, y1_pos);
				obstacleSprite.setScale(3, 8.53);
			}
			else
			{
				obstacleSprite.setTexture(obstacleTextures[i]);
				obstacleSprite.setTextureRect(sf::IntRect(0,0,30,30));
				obstacleSprite.setPosition(640, y2_pos);
				obstacleSprite.setScale(3, 8.53);
			}
			
			obstacleSprites.push_back(obstacleSprite);
		}			
	}
	
		
	for(auto it = obstacleSprites.begin(); it!=obstacleSprites.end();)
	{
		sf::Vector2f position = it->getPosition();
		if(position.x<-90)
		{
			gameOverFlag = true;
			//int i = std::distance(obstacleSprites.begin(), it);
			//obstacleTextures.erase(obstacleTextures.begin()+i);
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
			herosprite.move(-1.f, 0.f);
		if(direction == 1)
			herosprite.move(1.f, 0.f);
			
			
		for(int i = 0; i < obstacleSprites.size(); i++)
		{
			obstacleSprites.at(i).move(-1.f, 0.0);
		}	
		
	}
		
	herosprite.move(0.f, +2.f);
	
	RemoveOldAndAddNewObstacle();
	
	if(Collision())
		gameOverFlag = true;
	
}

void Singleplayer::HandleEvents(GameEngine* game)
{

	if(!gameOverFlag)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)) { herosprite.move(-0.0, -4.0); direction = 0; } //первая координата Х отрицательна =>идём влево
		if (Keyboard::isKeyPressed(Keyboard::Right)) { herosprite.move(0.0, -4.0);  direction = 1; } //первая координата Х положительна =>идём вправо
		if (Keyboard::isKeyPressed(Keyboard::Up)) { herosprite.move(0, -0.5); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
		if (Keyboard::isKeyPressed(Keyboard::Down)) { herosprite.move(0, 0.5); } //вторая координата (У) положительна =>идём вниз (если не понятно почему именно вниз - смотрим предыдущие уроки
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Escape)) { game->PopState();}
}

void Singleplayer::Draw(RenderWindow& window)
{
		if(gameOverFlag)
			window.draw(gameOverText);
			
		window.draw(herosprite);
		
		for(int i = 0; i < obstacleSprites.size(); i++)
		{
			window.draw(obstacleSprites[i]);
		}
}
