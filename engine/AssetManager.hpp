#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include "DEFINITIONS.hpp"

namespace bEngine
{
    class AssetManager
    {
    public:
        AssetManager() {}
        ~AssetManager() {}
        void LoadTexture(std::string name, std::string fileName);
        sf::Texture &GetTexture(std::string name);
        std::map<std::string, sf::Texture> &GetTexturesRaw();
        void SetTexture(std::string name, sf::Texture tex);
        void SetTexturesRaw(std::map<std::string, sf::Texture> textures);

        void LoadFont(std::string name, std::string fileName);
        sf::Font &GetFont(std::string name);
        std::map<std::string, sf::Font> &GetFontsRaw();
        void SetFontsRaw(std::map<std::string, sf::Font> fonts);

        /*void loadAudio(std::string name, std::string fileName);
        sf::Audio &GetAudio(std::string name);*/
    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}
