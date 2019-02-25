#include "play.h"
#include "screenhandler.h"
#include "fontholder.h"

Play::Play():
Bback(100, 45, "Back"),
board(),
score(0),
highscore(0),
text(){
    this->board.play = this;
    std::ifstream in("highscore.txt");
    in >> this->highscore;
    this->text.setFont(fontsholder.get(Fonts::RobotoCondensed_Regular));
    this->addPoints(0);
    this->text.setFillColor(sf::Color::Black);
    this->text.move(50, 50);
    this->Bback.move(800, 25);
    this->board.move(75, 100);
    this->Bback.scaleText(sf::Vector2f(2, 1));
    this->loadPieces();
}

void Play::update(sf::Time dt, sf::Vector2f pos){
    if(this->Bback.check(pos)){
        this->Bback.mark();
    }else{
        this->Bback.unmark();
    }
    this->board.update(dt, pos);
    for(int i = 0; i < 3; i++){
        if(this->pieces[i].check(pos)){
            this->pieces[i].mark();
        }else{
            this->pieces[i].unmark();
        }
        if(this->pieces[i].getDragged()){
            board.suggest(this->pieces[i].getTiles(), pos);
            this->pieces[i].setPosition(pos);
        }else{
            this->pieces[i].setPosition(675, 175 + i * 150);
        }
    }
    if(this->pieces[0].isPlaced() && this->pieces[1].isPlaced() && this->pieces[2].isPlaced()) this->loadPieces();
    if(this->isLost()) this->restart();
}

bool Play::isLost(){
    for(int i = 0; i < 3; i++){
        if(this->pieces[i].isPlaced()) continue;
        if(this->board.canPlay(this->pieces[i].getTiles())){
            return false;
        }
    }
    return true;
}

void Play::click(sf::Vector2f pos){
    if(this->Bback.getMarked()){
        this->sh->changePhase(ScreenPhase::MENU);
    }else{
        for(int i = 0; i < 3; i++){
            if(this->pieces[i].getMarked()){
                if(this->pieces[i].getDragged()){
                    if(this->board.isAnyMarked() && this->board.place(this->pieces[i].getTiles(), pos)){
                        this->pieces[i].place();
                    }else{
                        this->pieces[i].undrag();
                    }
                }else{
                    this->pieces[i].drag();
                }
            }
        }
    }
}

void Play::addPoints(int points){
    this->score += points;
    this->highscore = std::max(this->highscore, this->score);
    this->text.setString("Highscore: " + std::to_string(this->highscore) + "\t\tScore: " + std::to_string(this->score));
}

void Play::loadPieces(){
    Pieces::Type t;
    Pieces::Color col;
    int scelta, c[] = {-1, -1, -1};
    for(int i = 0; i < 3; i++){
        scelta = rand() % 31;
        if(scelta == 0)         t = Pieces::SBlock;
        else if(scelta == 1)    t = Pieces::DBlock;
        else if(scelta == 2)    t = Pieces::TBlock;
        else if(scelta == 3)    t = Pieces::VI2;
        else if(scelta == 4)    t = Pieces::VI3;
        else if(scelta == 5)    t = Pieces::VI4;
        else if(scelta == 6)    t = Pieces::VI5;
        else if(scelta == 7)    t = Pieces::HI2;
        else if(scelta == 8)    t = Pieces::HI3;
        else if(scelta == 9)    t = Pieces::HI4;
        else if(scelta == 10)   t = Pieces::HI5;
        else if(scelta == 11)   t = Pieces::VT;
        else if(scelta == 12)   t = Pieces::HT;
        else if(scelta == 13)   t = Pieces::R1T;
        else if(scelta == 14)   t = Pieces::R2T;
        else if(scelta == 15)   t = Pieces::VL11;
        else if(scelta == 16)   t = Pieces::HL11;
        else if(scelta == 17)   t = Pieces::R1L11;
        else if(scelta == 18)   t = Pieces::R2L11;
        else if(scelta == 19)   t = Pieces::VL12;
        else if(scelta == 20)   t = Pieces::HL12;
        else if(scelta == 21)   t = Pieces::R1L12;
        else if(scelta == 22)   t = Pieces::R2L12;
        else if(scelta == 23)   t = Pieces::VL21;
        else if(scelta == 24)   t = Pieces::HL21;
        else if(scelta == 25)   t = Pieces::R1L21;
        else if(scelta == 26)   t = Pieces::R2L21;
        else if(scelta == 27)   t = Pieces::VL22;
        else if(scelta == 28)   t = Pieces::HL22;
        else if(scelta == 29)   t = Pieces::R1L22;
        else if(scelta == 30)   t = Pieces::R2L22;
        do{
            scelta = rand() % 6;
        }while(scelta == c[(i + 1) % 3] || scelta == c[(i + 2) % 3]);
        c[i] = scelta;
        if(scelta == 0)         col = Pieces::Color::Red;
        else if(scelta == 1)    col = Pieces::Color::Blue;
        else if(scelta == 2)    col = Pieces::Color::Green;
        else if(scelta == 3)    col = Pieces::Color::LightBlue;
        else if(scelta == 4)    col = Pieces::Color::DarkGreen;
        else if(scelta == 5)    col = Pieces::Color::Orange;
        this->pieces[i] = Piece(t, col, 90);
        this->pieces[i].move(675, 175 + i * 150);
    }
}

void Play::restart(){
    std::ofstream out("highscore.txt");
    out << this->highscore;
    this->score = 0;
    this->addPoints(0);
    this->board.restart();
    this->loadPieces();
}

void Play::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    rt.draw(this->Bback, rs);
    rt.draw(this->board, rs);
    for(int i = 0; i < 3; i++)
        if(!this->pieces[i].getDragged()) rt.draw(this->pieces[i], rs);
    for(int i = 0; i < 3; i++)
        if(this->pieces[i].getMarked() && !this->pieces[i].getDragged()) rt.draw(this->pieces[i], rs);
    for(int i = 0; i < 3; i++)
        if(this->pieces[i].getDragged()) rt.draw(this->pieces[i], rs);
    rt.draw(this->text, rs);
}
