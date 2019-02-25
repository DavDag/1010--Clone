#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>
#include "button.h"

class ScreenHandler;

class Settings: public sf::Drawable, public sf::Transformable{
    public:
        ScreenHandler* sh;
        Settings();
        void update(sf::Time dt, sf::Vector2f pos);
        void click(sf::Vector2f pos);
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        Button Bback, Breset;
};

#endif // SETTINGS_H
