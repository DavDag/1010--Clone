#include "piece.h"
#include "textureholder.h"
#include "tile.h"

Piece::Piece(){
}

Piece::Piece(Pieces::Type t, Pieces::Color c, float rot):
type(t),
marked(false),
placed(false),
dragged(false){
    switch(this->type){
        case Pieces::SBlock:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            break;
        case Pieces::DBlock:
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                    this->tiles.push_back(Tile(25, 25, i, j));
            break;
        case Pieces::TBlock:
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    this->tiles.push_back(Tile(25, 25, i, j));
            break;
        case Pieces::VI2:
            for(int i = 0; i < 2; i++)
                this->tiles.push_back(Tile(25, 25, 0, i));
            break;
        case Pieces::HI2:
            for(int i = 0; i < 2; i++)
                this->tiles.push_back(Tile(25, 25, i, 0));
            break;
        case Pieces::VI3:
            for(int i = 0; i < 3; i++)
                this->tiles.push_back(Tile(25, 25, 0, i));
            break;
        case Pieces::HI3:
            for(int i = 0; i < 3; i++)
                this->tiles.push_back(Tile(25, 25, i, 0));
            break;
        case Pieces::VI4:
            for(int i = 0; i < 4; i++)
                this->tiles.push_back(Tile(25, 25, 0, i));
            break;
        case Pieces::HI4:
            for(int i = 0; i < 4; i++)
                this->tiles.push_back(Tile(25, 25, i, 0));
            break;
        case Pieces::VI5:
            for(int i = 0; i < 5; i++)
                this->tiles.push_back(Tile(25, 25, 0, i));
            break;
        case Pieces::HI5:
            for(int i = 0; i < 5; i++)
                this->tiles.push_back(Tile(25, 25, i, 0));
            break;
        case Pieces::VT:
            for(int i = 0; i < 3; i++)
                this->tiles.push_back(Tile(25, 25, i, 0));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            break;
        case Pieces::HT:
            for(int i = 0; i < 3; i++)
                this->tiles.push_back(Tile(25, 25, i, 1));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            break;
        case Pieces::R1T:
            for(int i = 0; i < 3; i++)
                this->tiles.push_back(Tile(25, 25, 1, i));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            break;
        case Pieces::R2T:
            for(int i = 0; i < 3; i++)
                this->tiles.push_back(Tile(25, 25, 0, i));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            break;
        case Pieces::VL11:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            break;
        case Pieces::R1L11:
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            break;
        case Pieces::HL11:
            this->tiles.push_back(Tile(25, 25, 1, 1));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            break;
        case Pieces::R2L11:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            break;
        case Pieces::VL12:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 0, 2));
            break;
        case Pieces::R1L12:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 2, 0));
            this->tiles.push_back(Tile(25, 25, 2, 1));
            break;
        case Pieces::HL12:
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            this->tiles.push_back(Tile(25, 25, 1, 2));
            this->tiles.push_back(Tile(25, 25, 0, 2));
            break;
        case Pieces::R2L12:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            this->tiles.push_back(Tile(25, 25, 2, 1));
            break;
        case Pieces::VL21:
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 2, 0));
            break;
        case Pieces::R1L21:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            this->tiles.push_back(Tile(25, 25, 1, 2));
            break;
        case Pieces::HL21:
            this->tiles.push_back(Tile(25, 25, 2, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 1, 1));
            this->tiles.push_back(Tile(25, 25, 2, 1));
            break;
        case Pieces::R2L21:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 0, 2));
            this->tiles.push_back(Tile(25, 25, 1, 2));
            break;
        case Pieces::VL22:
            this->tiles.push_back(Tile(25, 25, 0, 2));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 2, 0));
            break;
        case Pieces::R1L22:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 1, 0));
            this->tiles.push_back(Tile(25, 25, 2, 0));
            this->tiles.push_back(Tile(25, 25, 2, 1));
            this->tiles.push_back(Tile(25, 25, 2, 2));
            break;
        case Pieces::HL22:
            this->tiles.push_back(Tile(25, 25, 2, 0));
            this->tiles.push_back(Tile(25, 25, 0, 2));
            this->tiles.push_back(Tile(25, 25, 1, 2));
            this->tiles.push_back(Tile(25, 25, 2, 1));
            this->tiles.push_back(Tile(25, 25, 2, 2));
            break;
        case Pieces::R2L22:
            this->tiles.push_back(Tile(25, 25, 0, 0));
            this->tiles.push_back(Tile(25, 25, 0, 1));
            this->tiles.push_back(Tile(25, 25, 0, 2));
            this->tiles.push_back(Tile(25, 25, 1, 2));
            this->tiles.push_back(Tile(25, 25, 2, 2));
            break;
        default:
            break;
    }
    for(auto &t : this->tiles)
            t.setColor(c);
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
}

sf::FloatRect Piece::getGlobalBounds(){
    if(this->placed) sf::FloatRect(-1, -1, 0, 0);
    int xmax = 0, ymax = 0;
    for(unsigned int i = 0; i < this->tiles.size(); i++){
        xmax = std::max(xmax, (int)this->tiles[i].getPosition().x);
        ymax = std::max(ymax, (int)this->tiles[i].getPosition().y);
    }
    xmax = (xmax + this->tiles[0].getWidth());
    ymax = (ymax + this->tiles[0].getHeight());
    sf::FloatRect rect(getPosition() - sf::Vector2f(xmax / 2, ymax / 2), sf::Vector2f(xmax, ymax));
    return rect;
}

bool Piece::check(sf::Vector2f pos){
    return this->getGlobalBounds().contains(pos);
}

void Piece::mark(){
    if(this->marked) return;
    this->marked = true;
    this->scale(2, 2);
}

void Piece::unmark(){
    if(!this->marked) return;
    this->marked = false;
    this->scale(0.5f, 0.5f);
}

bool Piece::getMarked() const{
    return this->marked;
}

void Piece::drag(){
    if(this->dragged) return;
    this->dragged = true;
}

void Piece::undrag(){
    if(!this->dragged) return;
    this->dragged = false;
}

bool Piece::getDragged() const{
    return this->dragged;
}

void Piece::place(){
    this->placed = true;
    this->tiles.clear();
}

bool Piece::isPlaced(){
    return this->placed;
}

std::vector<Tile>& Piece::getTiles(){
    return this->tiles;
}

void Piece::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    for(auto &t : this->tiles)
            rt.draw(t, rs);
}
