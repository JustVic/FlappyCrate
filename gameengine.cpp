#include "gameengine.h"
#include <stdio.h>
#include "intro.h"
#include "singleplayer.h"

//#include <filesystem>
#include <fstream>
//
//#include <stdexcept>

extern int draw;

using namespace sf;
bool GameEngine::Init(void)
{
	window.create(sf::VideoMode(640, 480), "Game");
	window.setVerticalSyncEnabled(true);
	std::shared_ptr<GameState> intro = std::shared_ptr<Intro>(new Intro(this));

	this->PushState(std::move(intro));

	running = true;

    return true;
}


void GameEngine::ToSinglePlayer() {
}

void GameEngine::ToHighscore() {

}

int GameEngine::ReadSave() {

	std::ifstream f("data/save2.txt");

	int Highlevel;// = 0;

	f >> Highlevel;
	std::cout << " Highlevel: " << Highlevel << "\n";

	f.close();

	return Highlevel;
}

void GameEngine::Save(int Highlevel) {

		int Highlevel_Old = this->ReadSave();

		std::cout << "Previous: " << Highlevel_Old << ", Highlevel: " << Highlevel << "\n";		

		if(Highlevel_Old<Highlevel){
			std::ofstream f("data/save2.txt");
			f << Highlevel;// << std::endl;
			std::cout << "Writing save file...\n";
			f.close();
		}
}

void GameEngine::ToSingleplayer()
{
	std::shared_ptr<GameState> singleplayer = std::shared_ptr<Singleplayer>(new Singleplayer(this));
	
	this->PushState(std::move(singleplayer));
}

void GameEngine::ChangeState(std::shared_ptr<GameState> state)
{

}

/*std::shared_ptr<RenderManager> GameEngine::GetRend()
{
    return this->renderer;
}*/

RenderWindow GameEngine::GetWindow()
{
	//return window;
}

void GameEngine::PushState(std::shared_ptr<GameState> state)
{
	states.push_back(std::move(state));
}

void GameEngine::PopState()
{
	states.pop_back();
}

void GameEngine::HandleEvents()
{
	running = window.isOpen();
	
	Event event;
	while (window.pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			GameEngine::Cleanup();
			window.close();
		}
	}
	
	states.back()->HandleEvents(this);
}

void GameEngine::Cleanup(void)
{

}

void GameEngine::Update()
{
	states.back()->Update(window);
}

void GameEngine::Draw(){
	window.clear();
	states.back()->Draw(window);
	window.display();
}
