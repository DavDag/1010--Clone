#include "board.h"
#include "play.h"

Board::Board():
marked(-1){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            this->matrix[i][j] = Tile(50, 50, i, j);
        }
    }
}

bool Board::isAnyMarked(){
    return this->marked > -1;
}

bool Board::canPlay(std::vector<Tile>& tiles){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            bool canBePlaced = true;
            for(Tile& t: tiles){
                if((i + t.x) > 9 || (j + t.y) > 9 ||
                   (!this->matrix[i + t.x][j + t.y].isEmpty() &&
                   !this->matrix[i + t.x][j + t.y].getAnimated()))
                    canBePlaced = false;
            }
            if(canBePlaced) return true;
        }
    }
    return false;
}

bool Board::place(std::vector<Tile>& tiles, sf::Vector2f pos){
    pos -= getPosition();
    int xmax = 0, ymax = 0;
    for(unsigned int i = 0; i < tiles.size(); i++){
        xmax = std::max(xmax, tiles[i].x);
        ymax = std::max(ymax, tiles[i].y);
    }
    xmax++;
    ymax++;
    if(xmax % 2 == 0){
        if(this->matrix[this->marked / 10][this->marked % 10].isLefter(pos)){
            xmax++;
        }
    }
    if(ymax % 2 == 0){
        if(!this->matrix[this->marked / 10][this->marked % 10].isUpper(pos)){
            ymax--;
        }
    }
    xmax >>= 1;
    ymax >>= 1;
    for(unsigned int i = 0; i < tiles.size(); i++){
        if(this->marked / 10 - xmax + tiles[i].x < 0 || this->marked / 10 - xmax + tiles[i].x > 9) return false;
        if(this->marked % 10 - ymax + tiles[i].y < 0 || this->marked % 10 - ymax + tiles[i].y > 9) return false;
        Tile t = this->matrix[this->marked / 10 - xmax + tiles[i].x][this->marked % 10 - ymax + tiles[i].y];
        if(!t.isEmpty()){
            return false;
        }
    }
    for(unsigned int i = 0; i < tiles.size(); i++){
        Tile& t = this->matrix[this->marked / 10 - xmax + tiles[i].x][this->marked % 10 - ymax + tiles[i].y];
        t.setColor(tiles[i].getColor());
    }
    this->play->addPoints(tiles.size() * 10);
    return true;
}

void Board::suggest(std::vector<Tile>& tiles, sf::Vector2f pos){
    pos -= getPosition();
    int xmax = 0, ymax = 0;
    for(unsigned int i = 0; i < tiles.size(); i++){
        xmax = std::max(xmax, tiles[i].x);
        ymax = std::max(ymax, tiles[i].y);
    }
    xmax++;
    ymax++;
    if(xmax % 2 == 0){
        if(this->matrix[this->marked / 10][this->marked % 10].isLefter(pos)){
            xmax++;
        }
    }
    if(ymax % 2 == 0){
        if(!this->matrix[this->marked / 10][this->marked % 10].isUpper(pos)){
            ymax--;
        }
    }
    xmax >>= 1;
    ymax >>= 1;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            this->matrix[i][j].suggest(false);
    if(this->marked == -1) return;
    for(unsigned int i = 0; i < tiles.size(); i++){
        if(this->marked / 10 - xmax + tiles[i].x < 0 || this->marked / 10 - xmax + tiles[i].x > 9) return;
        if(this->marked % 10 - ymax + tiles[i].y < 0 || this->marked % 10 - ymax + tiles[i].y > 9) return;
        Tile t = this->matrix[this->marked / 10 - xmax + tiles[i].x][this->marked % 10 - ymax + tiles[i].y];
        if(!t.isEmpty()){
            return;
        }
    }
    for(unsigned int i = 0; i < tiles.size(); i++){
        Tile& t = this->matrix[this->marked / 10 - xmax + tiles[i].x][this->marked % 10 - ymax + tiles[i].y];
        t.suggest(true);
    }
}

void Board::restart(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            this->matrix[i][j].animate();
        }
    }
}

void Board::update(sf::Time dt, sf::Vector2f pos){
    pos -= getPosition();
    this->marked = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            this->matrix[i][j].update(dt);
            if(this->matrix[i][j].check(pos)){
                this->matrix[i][j].mark();
                this->marked = i * 10 + j;
            }else{
                this->matrix[i][j].unmark();
            }
        }
    }
    this->erase10();
}

void Board::erase10(){
    std::vector<std::pair<int, int> > toBeErased;
    for(int i = 0; i < 10; i++){
        bool tmpC = true, tmpR = true;
        for(int j = 0; j < 10; j++){
            if(this->matrix[i][j].isEmpty())
                tmpR = false;
            if(this->matrix[j][i].isEmpty())
                tmpC = false;
        }
        if(tmpR){
            for(int j = 0; j < 10; j++)
                toBeErased.push_back({i, j});
        }
        if(tmpC){
            for(int j = 0; j < 10; j++)
                toBeErased.push_back({j, i});
        }
    }
    for(std::pair<int, int>& p : toBeErased)
        this->matrix[p.first][p.second].animate();
    if(toBeErased.size() > 0)
        this->play->addPoints(toBeErased.size() * (15 + toBeErased.size()));
}

void Board::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            rt.draw(this->matrix[i][j], rs);
}
