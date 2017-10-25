#include <sstream>
#include "SplashState.hpp"

#include <iostream>

namespace bEngine
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash Background", SPLASH_BACKGROUND);
		//_data->assets.GetTexture("Splash Background").setSmooth(true);
		_background.setTexture(this->_data->assets.GetTexture("Splash Background"));
		_background.setScale(SCREEN_WIDTH / _background.getLocalBounds().width, SCREEN_HEIGHT / _background.getLocalBounds().width);
		_background.setPosition(0, (SCREEN_HEIGHT - _background.getGlobalBounds().height) / 2);
		_background.setColor(sf::Color(255,255,255, (int)_alpha));
	}

	void SplashState::Input()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            _data->window.close();
        }
	}

	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() >= SPLASH_DURATION)
		{
			_data->machine.AddState(StateRef(new MainMenuState(this->_data)));
		}
		else if(_clock.getElapsedTime().asMilliseconds() <= SPLASH_FADE_IN_END * 1000)
        {
            _alpha += (255.0f / (SPLASH_FADE_IN_END * 60.0f));
        }
		else if (_clock.getElapsedTime().asSeconds() >= SPLASH_FADE_OUT_START)
        {
            _alpha -= 255.0f / ((SPLASH_DURATION - SPLASH_FADE_OUT_START) * 60.0f);
        }
        _background.setColor(sf::Color(255,255,255, (int)_alpha));
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color(155,255,155));

		this->_data->window.draw( this->_background );

		this->_data->window.display();
	}
}
