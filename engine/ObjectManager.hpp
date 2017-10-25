#ifndef OBJECTMANAGER_HPP
#define OBJECTMANAGER_HPP

#include "Object.hpp"
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <sstream>

namespace bEngine{

    template <class ANY>
    int toInt(ANY ob)
    {
        int ans;
        std::stringstream con;
        con << ob;
        con >> ans;
        return ans;
    }

    template <class ANY>
    std::string toString(ANY ob)
    {
        std::string ans;
        std::stringstream con;
        con << ob;
        con >> ans;
        return ans;
    }

    typedef std::unique_ptr<Object> ObjectRef;

    class ObjectManager
    {
    public:
        ObjectManager(){};
        void AddObject(std::string name, ObjectRef object);
        void RemoveObject(std::string name);
        void RemoveObject(unsigned int ind);
        ObjectRef &GetByName(std::string name);
        ObjectRef &GetByTag(std::string tag);
        ObjectRef &GetByIndex(unsigned int ind);
        ObjectRef &GetNthByTag(std::string tag, unsigned int nth = 1);
        std::vector<ObjectRef> &GetRaw();
        bool ExistsByName(std::string name);
        bool ExistsByTag(std::string name);
        unsigned int index(std::string name);

    private:
        std::vector<ObjectRef> _objects;
    };
}

#endif // OBJECTMANAGER_HPP
