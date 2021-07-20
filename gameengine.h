#ifndef gameengine_h
#define gameengine_h

#include <vector>
#include <functional>
#include <memory>
#include <iostream>
//#include "renderer.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class GameState;

class GameEngine : public std::enable_shared_from_this<GameEngine>
{
	private:
        bool running;
		RenderWindow window;

        std::shared_ptr<GameState> currentState;
        std::vector<std::shared_ptr<GameState>> states;

    public:

		bool Init();

		void Cleanup();

		int ReadSave();

		void Save(int Highlevel);

		void ToSinglePlayer();

		void ToHighscore();
		
		RenderWindow GetWindow();

		void ChangeState(std::shared_ptr<GameState> state);
		
		void ToSingleplayer();

		void PushState(std::shared_ptr<GameState> state);

		void PopState();

		void HandleEvents();

		void Update();

		void Draw();

		bool Running() { return running; }

		void Quit() { running = false; }
};

#endif

