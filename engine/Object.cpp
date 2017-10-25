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
}
