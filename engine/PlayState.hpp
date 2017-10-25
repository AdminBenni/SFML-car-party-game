#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP
#include "State.hpp"
#include "Game.hpp"
#include "car.hpp"
#include <vector>

namespace bEngine{
    class PlayState : public State
    {
    public:
        PlayState(GameDataRef data);
        void Init();
        void Input();
        void Update(float dt);
        void Draw(float dt);
    private:
        GameDataRef _data;

        std::vector<Car> _cars;
        std::vector<KeySet> _keySets = {KeySet{sf::Keyboard::Left, sf::Keyboard::Right}, KeySet{sf::Keyboard::A, sf::Keyboard::D}, KeySet{sf::Keyboard::Z, sf::Keyboard::X}};
        std::vector<sf::Color> _colors = {sf::Color::White, sf::Color::Green, sf::Color::Red};

    };
}

#endif // PLAYSTATE_HPP
