#include "settings.h"
#include "screenhandler.h"
#include "play.h"

Settings::Settings():
Bback(200, 75, "Back"),
Breset(200, 75, "Reset"){
    this->Bback.move(380, 150);
    this->Breset.move(380, 250);
}

void Settings::update(sf::Time dt, sf::Vector2f pos){
    if(this->Bback.check(pos)){
        this->Bback.mark();
    }else{
        this->Bback.unmark();
    }
    if(this->Breset.check(pos)){
        this->Breset.mark();
    }else{
        this->Breset.unmark();
    }
}

void Settings::click(sf::Vector2f pos){
    if(this->Bback.getMarked()){
        this->sh->changePhase(ScreenPhase::MENU);
    }
    if(this->Breset.getMarked()){
        this->sh->changePhase(ScreenPhase::PLAYING);
        this->sh->play->restart();
    }
}

void Settings::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    rt.draw(this->Bback, rs);
    rt.draw(this->Breset, rs);
}
