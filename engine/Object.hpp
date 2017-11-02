#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <Collision.hpp>
//#include "Game.hpp"


namespace bEngine
{
    struct GameData;
    typedef std::shared_ptr<GameData> GameDataRef;

    class Object : public sf::Sprite
    {
    public:
        Object(){};
        virtual ~Object(){};
        virtual void Init  (GameDataRef data){};
        virtual void Input (float dt, GameDataRef data){};
        virtual void Update(float dt, GameDataRef data){};
        //virtual void Draw  (float dt, GameDataRef data){};
        virtual void OnCollisionEnter(Object& collision, GameDataRef data){};
        virtual void OnCollisionStay (Object& collision, GameDataRef data){};
        virtual void OnCollisionExit (Object& collision, GameDataRef data){};
        virtual void OnClicked(GameDataRef data){};

        /**       Actions       **/
        virtual void Action1 (GameDataRef data, std::string str = ""){};
        virtual void Action2 (GameDataRef data, std::string str = ""){};
        virtual void Action3 (GameDataRef data, std::string str = ""){};
        virtual void Action4 (GameDataRef data, std::string str = ""){};
        virtual void Action5 (GameDataRef data, std::string str = ""){};
        virtual void Action6 (GameDataRef data, std::string str = ""){};
        virtual void Action7 (GameDataRef data, std::string str = ""){};
        virtual void Action8 (GameDataRef data, std::string str = ""){};
        virtual void Action9 (GameDataRef data, std::string str = ""){};
        virtual void Action10(GameDataRef data, std::string str = ""){};
        virtual void Action11(GameDataRef data, std::string str = ""){};
        virtual void Action12(GameDataRef data, std::string str = ""){};
        virtual void Action13(GameDataRef data, std::string str = ""){};
        virtual void Action14(GameDataRef data, std::string str = ""){};
        virtual void Action15(GameDataRef data, std::string str = ""){};
        virtual void Action16(GameDataRef data, std::string str = ""){};

        std::string GetTag();
        std::string GetName();
        sf::Sprite &getAttached(std::string name);
        std::vector<sf::Sprite> getAttachedRaw();
        std::vector<std::string> getAttachedNamesRaw();
        bool ToBeDrawn(bool val = true);
        bool Collidable();
        bool Collidable(bool val);
        void SetTag(std::string tag);
        void SetName(std::string name);
        void addAttachable(std::string name, sf::Sprite sprite = sf::Sprite());
    protected:
        bool _toBeDrawn = true;
        std::string _tag;
        std::string _name;
        bool _collidable = false;
        std::vector<sf::Sprite> _att;
        std::vector<std::string> _attNames;
    };
}


#endif // OBJECT_HPP_INCLUDED
