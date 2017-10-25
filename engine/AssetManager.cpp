#include "AssetManager.hpp"

namespace bEngine
{
    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture tex;

        if(tex.loadFromFile(fileName))
        {
            this->_textures[name] = tex;
        }
        else
        {
            tex.loadFromFile(NO_LOAD_TEXTURE);
            this->_textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return this->_textures.at(name);
    }

    std::map<std::string, sf::Texture> &AssetManager::GetTexturesRaw()
    {
        return _textures;
    }

    void AssetManager::SetTexture(std::string name, sf::Texture tex)
    {
        _textures[name] = tex;
    }

    void AssetManager::SetTexturesRaw(std::map<std::string, sf::Texture> textures)
    {
        _textures = textures;
    }

    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;

        if(font.loadFromFile(fileName))
        {
            this->_fonts[name] = font;
        }
        else
        {
            font.loadFromFile("engine/Resources/fonts/arial.ttf");
            this->_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name)
    {
        return this->_fonts.at(name);
    }

    std::map<std::string, sf::Font> &AssetManager::GetFontsRaw()
    {
        return _fonts;
    }

    void AssetManager::SetFontsRaw(std::map<std::string, sf::Font> fonts)
    {
        _fonts = fonts;
    }
}
