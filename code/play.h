#pragma once
#ifndef PLAY_H
#define PLAY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "button.h"
#include "board.h"
#include "piece.h"

class ScreenHandler;

class Play: public sf::Drawable, public sf::Transformable{
    public:
        ScreenHandler* sh;
        Play();
        void update(sf::Time dt, sf::Vector2f pos);
        void loadPieces();
        void restart();
        bool isLost();
        void addPoints(int points);
        void click(sf::Vector2f pos);
    private:
        virtual void draw(sf::RenderTarget& rt, sf::RenderStates rs) const;
        Button Bback;
        Board board;
        Piece pieces[3];
        int score, highscore;
        sf::Text text;
};

#endif // PLAY_H
