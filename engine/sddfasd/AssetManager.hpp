#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <map>
#include <string>

namespace bEngine
{
    class AssetManager
    {
    public:
        AssetManager() {}
        ~AssetManager() {}
        void LoadTexture(std::string name, std::string fileName);
        sf::Texture &GetTexture(std::string name);

        void LoadFont(std::string name, std::string fileName);
        sf::Font &GetFont(std::string name);

        /*void loadAudio(std::string name, std::string fileName);
        sf::Audio &GetAudio(std::string name);*/
    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}


#endif // ASSETMANAGER_HPP
