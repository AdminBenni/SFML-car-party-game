#include <SFML/Graphics.hpp>
#include "engine/Game.hpp"
#include <string>
#include <iostream>
#include <windows.h>
#include "DEFINITIONS.hpp"
#include "car.hpp"

using namespace std;

int main()
{
    bEngine::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Plz virka plxxxzzzzzzz");
    /*sf::RenderWindow window(sf::VideoMode(800, 800), "Lol", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape shape(sf::Vector2f(50.0f, 50.0f));
    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Red);
        window.draw(shape);
        window.display();
    }*/
    return 0;
}
