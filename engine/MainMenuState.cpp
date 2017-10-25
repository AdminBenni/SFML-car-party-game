#include "MainMenuState.hpp"
namespace bEngine{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
        srand(time(0));
    }

    void MainMenuState::Init()
    {
        /*rot.setSize(sf::Vector2f(200, 200));
        rot.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        rot.setOrigin(rot.getGlobalBounds().width / 2, rot.getGlobalBounds().height / 2);
        rot.setFillColor(sf::Color::Red);*/
        _data->assets.LoadTexture("Delorean", DELOREAN);
        this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON);
        this->_data->assets.LoadTexture("Play Button Pressed", PLAY_BUTTON_PRESSED);
        _playButton.setTexture(_data->assets.GetTexture("Play Button"));
        _playButton.setScale(SCREEN_WIDTH / _playButton.getLocalBounds().width * 0.5, SCREEN_WIDTH / _playButton.getLocalBounds().width * 0.5);
        _playButton.setPosition((SCREEN_WIDTH - _playButton.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - _playButton.getGlobalBounds().height) / 2);
        _playButton.setColor(sf::Color(255,255,255, (int)_alpha));
    }

    void MainMenuState::Input()
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

    void MainMenuState::Update(float dt)
    {
        if(_clock.getElapsedTime().asMilliseconds() <= MAIN_MENU_FADE_IN_END * 1000)
        {
            _alpha += (255.0f / (MAIN_MENU_FADE_IN_END * 60.0f));
        }
        else
        {
            if(_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
            {
                pressFrames++;
            }
            else if(!_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window) && pressFrames > 0)
            {
                pressFrames = 0;
                _playButton.setTexture(_data->assets.GetTexture("Play Button"));
                this->_data->window.clear(sf::Color(155,255,155));
                this->_data->window.draw(_playButton);
                this->_data->window.display();
                Sleep(200);
                _data->machine.AddState(StateRef(new PlayState(_data)));
            }
            if(pressFrames >= 3)
            {
                _playButton.setTexture(_data->assets.GetTexture("Play Button Pressed"));
            }
        }
        //rot.rotate(0.5f);
        _playButton.setColor(sf::Color(255,255,255, (int)_alpha));
    }

    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color(155,255,155));
        //this->_data->window.draw(rot);
        this->_data->window.draw(_playButton);
        this->_data->window.display();
    }
}
