#ifndef CAR_HPP
#define CAR_HPP
#include "Game.hpp"
#include <cmath>
#include "Object.hpp"
#include <iostream>

namespace bEngine{

    /*enum Direction{
        Straight = 0,
        Left = 1,
        Right = 2,
        Backwards = 3
    };*/

    inline long forceRange(long x, long in_min, long in_max, long out_min, long out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    struct KeySet
    {
        sf::Keyboard::Key leftKey;
        sf::Keyboard::Key rightKey;
    };

    class Car : public Object
    {
        public:
            Car(GameDataRef data, float speed = 10, float rSpeed = 7, std::string texName = "", KeySet keys = KeySet(), std::string tag = "");
            //bool isRotating();
            //Direction direction();
            //void setDirection(Direction dir);
            float getSpeed();
            void setSpeed(float speed);
            float getRotationSpeed();
            void setRotationSpeed(float speed);
            float getAngle();
            void setAngle(float angle);
            float getBounce();
            void setBounce(float bounce);
            KeySet getKeys();
            void setKeys(sf::Keyboard::Key leftKey, sf::Keyboard::Key rightKey);
            void setKeys(KeySet keySet);

            //Object
            void Init(GameDataRef data){};
            void Input(float dt, GameDataRef data);
            void Update(float dt, GameDataRef data);
            void Draw(float dt, GameDataRef data);
            void OnCollisionEnter(Object& collision, GameDataRef data);

            //Actions
            void Action1(GameDataRef data, std::string str);
        private:
            float _bounce;
            //Direction _dir = Straight;
            bool _aUpdating;
            const float _aUpdatingTime = 1.5;
            float _angle;
            float _speed = 0.1f;
            float _rSpeed = 0.1f;
            KeySet _keys;
            const float _bounceStrength = -1.3;
            const float _bounceDegeneration = 0.1f;
            const float _collisionAngleDegeneration = 0.1f;
            float _collisionAngle = 1;
            /*sf::RectangleShape _fCollider;
            sf::RectangleShape _bCollider;*/
    };
}

#endif // CAR_HPP
