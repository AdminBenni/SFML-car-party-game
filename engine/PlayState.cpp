#include "PlayState.hpp"
#include <iostream>
#include <cmath>
namespace bEngine{
    PlayState::PlayState(GameDataRef data) : _data(data) {}

    void PlayState::Init()
    {
        _data->assets.SetTexture("Delorean", sf::Texture());
        CreateTextureAndBitmask(_data->assets.GetTexture("Delorean"), DELOREAN);
        for(unsigned int i = 0; i < _keySets.size(); i++)
        {
            _data->objects.AddObject("Car " + toString(i), ObjectRef(new Car(
                _data,
                10,
                7,
                "Delorean",
                KeySet{_keySets[i].leftKey, _keySets[i].rightKey},
                "Car",
                "Car " + toString(i)
            )));
            _data->objects.GetByName("Car " + toString(i))->setScale(2,2);
            _data->objects.GetByName("Car " + toString(i))->setOrigin(_data->objects.GetByName("Car " + toString(i))->getLocalBounds().width / 2, _data->objects.GetByName("Car " + toString(i))->getLocalBounds().height / 2);
            _data->objects.GetByName("Car " + toString(i))->setPosition(_data->objects.GetByName("Car " + toString(i))->getGlobalBounds().width / 2, (i * 100) + _data->objects.GetByName("Car " + toString(i))->getLocalBounds().height);
            std::cout << _data->objects.GetByName("Car " + toString(i))->getGlobalBounds().width << " : " << _data->objects.GetByName("Car " + toString(i))->getGlobalBounds().height << std::endl;
            _data->objects.GetByName("Car " + toString(i))->Collidable(true);
        }
        Sleep(300);
    }

    void PlayState::Input()
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            for(unsigned int i = 0; i < _data->objects.GetRaw().size(); i++)
            {
                int ind = _data->objects.index("Car " + toString(i));
                if(ind != - 1)
                    _data->objects.RemoveObject(ind);
            }
            _data->machine.AddState(StateRef(new PlayState(_data)));
        }
    }

    void PlayState::Update(float dt)
    {

    }

    void PlayState::Draw(float dt)
    {
        _data->window.clear(sf::Color::Magenta);
        for(unsigned int i = 0; i < _data->objects.GetRaw().size(); i++)
        {
            if(_data->objects.index("Car " + toString(i)) != -1)
            {
                _data->window.draw(*_data->objects.GetByName("Car " + toString(i)));
                _data->window.draw(_data->objects.GetByName("Car " + toString(i))->getAttached("Front Collider"));
                _data->window.draw(_data->objects.GetByName("Car " + toString(i))->getAttached("Back Collider"));
            }
        }
        _data->window.display();
    }
}
