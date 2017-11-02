#include "Object.hpp"
namespace bEngine
{
    std::string Object::GetTag()
    {
        return _tag;
    }

    void Object::SetTag(std::string tag)
    {
        _tag = tag;
    }

    std::string Object::GetName()
    {
        return _name;
    }

    void Object::SetName(std::string name)
    {
        _name = name;
    }

    bool Object::ToBeDrawn(bool val)
    {
        _toBeDrawn = val;
        return _toBeDrawn;
    }

    bool Object::Collidable()
    {
        return _collidable;
    }

    bool Object::Collidable(bool val)
    {
        _collidable = val;
        return _collidable;
    }

    void Object::addAttachable(std::string name, sf::Sprite trans)
    {
        _att.push_back(trans);
        _attNames.push_back(name);
    }

    sf::Sprite &Object::getAttached(std::string name)
    {
        for(unsigned int i = 0; i < _attNames.size(); i++)
        {
            if(_attNames[i] == name)
                return _att[i];
        }
    }

    std::vector<sf::Sprite> Object::getAttachedRaw()
    {
        return _att;
    }

    std::vector<std::string> Object::getAttachedNamesRaw()
    {
        return _attNames;
    }
}
