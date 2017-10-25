#include "Game.hpp"
#include "SplashState.hpp"
#include "PlayState.hpp"
namespace bEngine
{
	Game::Game(int width, int height, std::string title)
	{
	    _data->assets.LoadTexture("No Load", NO_LOAD_TEXTURE);
		_data->window.create(sf::VideoMode(width, height), title, /*sf::Style::Fullscreen*/ sf::Style::Close | sf::Style::Titlebar);
		//_data->machine.AddState(StateRef(new SplashState(this->_data)));
		_data->machine.AddState(StateRef(new PlayState(this->_data)));

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->Input();
                for(unsigned int i = 0; i < _data->objects.GetRaw().size(); i++)
                {
                    _data->objects.GetByIndex(i)->Input(dt, _data);
                }
				this->_data->machine.GetActiveState()->Update(dt);
				for(unsigned int i = 0; i < _data->objects.GetRaw().size(); i++)
                {
                    _data->objects.GetByIndex(i)->Update(dt, _data);
                }
                for(unsigned int i = 0; i < _data->objects.GetRaw().size(); i++)
                {
                    ObjectRef& obj1 = _data->objects.GetByIndex(i);
                    if(obj1->Collidable())
                    {
                        for(unsigned int j = i + 1; j < _data->objects.GetRaw().size(); j++)
                        {
                            ObjectRef& obj2 = _data->objects.GetByIndex(j);
                            if(obj2->Collidable())
                            {
                                if(BoundingBoxTest(*obj1, *obj2))
                                {
                                    obj1->OnCollisionEnter(*obj2, _data);
                                    obj2->OnCollisionEnter(*obj1, _data);
                                }
                            }
                        }
                    }
                }

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			//_data->window.clear();
			this->_data->machine.GetActiveState()->Draw(interpolation);
			/*gotoxy(0, 0);
			std::cout << fmod(_clock.getElapsedTime().asSeconds(), 1) - interpolation << "        " << std::endl;*/
			/*for(unsigned int i = 0; i < _data->objects.GetRaw().size(); i++)
            {
                if(_data->objects.GetByIndex(i)->ToBeDrawn())
                    _data->objects.GetByIndex(i)->Draw(interpolation, _data);
            }*/
            //_data->window.display();
            /*_frames++;
            if(_frameClock.getElapsedTime().asMilliseconds() >= 1000)
            {
                _frameClock.restart();
                gotoxy(0, 0);
                std::cout << _frames << "        " << std::endl;
                _frames = 0;
            }*/
		}
	}
}
