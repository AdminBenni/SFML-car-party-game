#pragma once
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "DEFINITIONS.hpp"
#include "ObjectManager.hpp"
#include <memory>
#include <string>
#include <Windows.h>
#include <cmath>
#include <vector>
#include <thread>

namespace bEngine
{
    inline void gotoxy(short x, short y)
    {
        static HANDLE h = NULL;
        if (!h)
            h = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c = { x, y };
        SetConsoleCursorPosition(h, c);
    }

	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		ObjectManager objects;
		//sf::Clock time = sf::Clock();
    };

	//typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		/*sf::Clock _frameClock;
		unsigned int _frames = 0;*/

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}
