#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "button.h"

class ScreenHandler;

class Menu: public sf::Drawable, public sf::Transformable{
    public:
        ScreenHandler* sh;
        Menu();
        ~Menu();
        void update(sf::Time dt, sf::Vector2f pos);
        void click(sf::Vector2f pos);
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        Button Bplay, Bsettings;
        sf::Sprite bg;
};

#endif // MENU_H
