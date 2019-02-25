#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "tile.h"

class Play;

class Board: public sf::Drawable, public sf::Transformable{
    public:
        Play* play;
        Board();
        bool isAnyMarked();
        void restart();
        void erase10();
        bool canPlay(std::vector<Tile>& tiles);
        void suggest(std::vector<Tile>& tiles, sf::Vector2f pos);
        bool place(std::vector<Tile>& tiles, sf::Vector2f pos);
        void update(sf::Time dt, sf::Vector2f pos);
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        Tile matrix[10][10];
        int marked;
};


#endif // BOARD_H
