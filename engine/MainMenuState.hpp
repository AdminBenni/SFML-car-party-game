#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP
#include "State.hpp"
#include "Game.hpp"
#include "PlayState.hpp"
#include <iostream>

namespace bEngine
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		// No pause() or resume() methods here as this
		// is a very simple example of a game state.

		void Input();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		unsigned int pressFrames = 0;

		sf::RectangleShape rot;

        sf::Sprite _playButton;

        sf::Clock _clock;

        float _alpha = 0;
	};
}

#endif // MAINMENUSTATE_HPP
