#pragma once
#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "textureholder.h"
#include "piece.h"

class Tile: public sf::Drawable, public sf::Transformable{
    public:
        int x, y;
        Tile();
        Tile(int width, int height, int i, int j);
        void setColor(Pieces::Color c);
        Pieces::Color getColor();
        bool check(sf::Vector2f pos);
        void mark();
        void unmark();
        bool getMarked();
        bool isEmpty();
        void animate();
        bool getAnimated();
        void suggest(bool sgg);
        bool isLefter(sf::Vector2f pos);
        bool isUpper(sf::Vector2f pos);
        sf::FloatRect getGlobalBounds();
        void update(sf::Time dt);
        int getWidth();
        int getHeight();
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        sf::Sprite sprite;
        bool marked, animated;
        Pieces::Color color;
        sf::Time trim, tmx;
};

#endif // TILE_H
