#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button: public sf::Drawable, public sf::Transformable{
    public:
        Button(int width, int height, std::string text);
        bool check(sf::Vector2f pos);
        void mark();
        void unmark();
        bool getMarked();
        void scaleText(sf::Vector2f Scale);
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        sf::Sprite sprite;
        bool marked;
        sf::Text text;
};

#endif // BUTTON_H
