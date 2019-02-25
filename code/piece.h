#pragma once
#ifndef PIECE_H
#define PIECE

#include <SFML/Graphics.hpp>

class Tile;

namespace Pieces{
    enum Type{  SBlock, DBlock, TBlock,
                VI2, VI3, VI4, VI5, HI2, HI3, HI4, HI5,
                VL11, VL12, VL21, VL22, HL11, HL12, HL21, HL22,
                R1L11, R1L12, R1L21, R1L22, R2L11, R2L12, R2L21, R2L22,
                VT, HT, R1T, R2T };
    enum Color{Red, Blue, LightBlue, Green, DarkGreen, Orange, Empty};
}

class Piece: public sf::Drawable, public sf::Transformable{
    public:
        Piece();
        Piece(Pieces::Type t, Pieces::Color c, float rot);
        void mark();
        void unmark();
        bool getMarked() const;
        bool isPlaced();
        void place();
        void drag();
        void undrag();
        bool getDragged() const;
        bool check(sf::Vector2f pos);
        std::vector<Tile>& getTiles();
        sf::FloatRect getGlobalBounds();
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        Pieces::Type type;
        std::vector<Tile> tiles;
        bool marked, placed, dragged;
};

#endif // PIECE_H
