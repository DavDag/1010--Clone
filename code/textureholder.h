#pragma once
#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace Textures{
    enum ID {   BlueButton, RedButton, RedButtonSelected, YellowButton, GreyButton, GreenButton,
                RedBlock, GreenBlock, BlueBlock, DarkGreenBlock, LightBlueBlock, OrangeBlock, EmptyBlock,
                Background};
}

class TextureHolder{
    public:
        TextureHolder();
        ~TextureHolder();
        void load(Textures::ID id, const std::string &filename);
        sf::Texture& get(Textures::ID id);
        const sf::Texture& get(Textures::ID id) const;
    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> TextureMap;
};

extern TextureHolder textureholder;

#endif // TEXTUREHOLDER_H

