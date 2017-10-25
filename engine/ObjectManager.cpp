#include "ObjectManager.hpp"

namespace bEngine
{
    void ObjectManager::AddObject(std::string name, ObjectRef object)
    {
        object->SetName(name);
        _objects.push_back(std::move(object));
    }

    void ObjectManager::RemoveObject(std::string name)
    {
        int i = index(name);
        delete _objects[i].release();
        _objects.erase(_objects.begin()+i);
    }

    void ObjectManager::RemoveObject(unsigned int ind)
    {
        delete _objects[ind].release();
        _objects.erase(_objects.begin()+ind);
    }

    ObjectRef &ObjectManager::GetByName(std::string name)
    {
        for(unsigned int i = 0; i < _objects.size(); i++)
        {
            if(_objects[i]->GetName() == name)
            {
                return _objects[i];
            }
        }
        throw std::out_of_range("Object with name " + name + " was not found");
    }

    ObjectRef &ObjectManager::GetByTag(std::string tag)
    {
        for(unsigned int i = 0; i < _objects.size(); i++)
        {
            if(_objects[i]->GetTag() == tag)
            {
                return _objects[i];
            }
        }
        throw std::out_of_range("Object with tag " + tag + " was not found");
    }

    ObjectRef &ObjectManager::GetNthByTag(std::string tag, unsigned int nth)
    {
        if(nth == 0)
            throw std::out_of_range("nth is not allowed to be 0");
        unsigned int occ = 0;
        for(unsigned int i = 0; i < _objects.size(); i++)
        {
            if(_objects[i]->GetTag() == tag)
            {
                occ++;
                if(occ == nth)
                    return _objects[i];
            }
        }
        throw std::out_of_range(toString(nth) + " occurrence of object with tag " + tag + " was not found");
    }

    bool ObjectManager::ExistsByName(std::string name)
    {
        for(unsigned int i = 0; i < _objects.size(); i++)
        {
            if(_objects[i]->GetName() == name)
                return true;
        }
        return false;
    }

    bool ObjectManager::ExistsByTag(std::string tag)
    {
        for(unsigned int i = 0; i < _objects.size(); i++)
        {
            if(_objects[i]->GetTag() == tag)
                return true;
        }
        return false;
    }

    unsigned int ObjectManager::index(std::string name)
    {
        for(unsigned int i = 0; i < _objects.size(); i++)
        {
            if(_objects[i]->GetName() == name)
            {
                return i;
            }
        }
        return -1;
    }

    std::vector<ObjectRef> &ObjectManager::GetRaw()
    {
        return _objects;
    }

    ObjectRef &ObjectManager::GetByIndex(unsigned int ind)
    {
        return _objects[ind];
    }
}
