#pragma once
#ifndef FONTHOLDER_H
#define FONTHOLDER_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace Fonts{
    enum ID {RobotoCondensed_Regular};
}

class FontHolder{
    public:
        FontHolder();
        ~FontHolder();
        void load(Fonts::ID id, const std::string &filename);
        sf::Font& get(Fonts::ID id);
        const sf::Font& get(Fonts::ID id) const;
    private:
        std::map<Fonts::ID, std::unique_ptr<sf::Font>> FontMap;
};

extern FontHolder fontsholder;

#endif // FONTHOLDER_H

