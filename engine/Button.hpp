#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>


class Button : public sf::Sprite
{
    public:
        virtual void action() = 0;

    private:
};

#endif // BUTTON_HPP
