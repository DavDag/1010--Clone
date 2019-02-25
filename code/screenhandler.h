#pragma once
#ifndef SCREENHANDLER_H
#define SCREENHANDLER_H

#include <SFML/Graphics.hpp>

class Menu;
class Settings;
class Play;

namespace ScreenPhase{
    enum Phase{MENU, PLAYING, PAUSE, SETTINGS};
}

class ScreenHandler: public sf::Drawable, public sf::Transformable{
    public:
        Menu* menu;
        Settings* settings;
        Play* play;
        ScreenHandler();
        ~ScreenHandler();
        void update(sf::Time dt, sf::Vector2f pos);
        void click(sf::Vector2f pos);
        void changePhase(ScreenPhase::Phase sp);
        sf::Color& getTheme();
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        ScreenPhase::Phase phase;
        sf::Color theme;
};

#endif // SCREENHANDLER_H
