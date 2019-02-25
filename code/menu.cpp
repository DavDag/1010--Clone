#include "menu.h"
#include "screenhandler.h"
#include "textureholder.h"

Menu::Menu():
Bplay(200, 75, "Play"),
Bsettings(200, 75, "Settings"),
bg(){
    this->bg.setTexture(textureholder.get(Textures::Background));
    this->Bsettings.setPosition(380, 350);
    this->Bplay.setPosition(380, 150);
}

Menu::~Menu(){
}

void Menu::click(sf::Vector2f pos){
    if(this->Bplay.getMarked()){
        this->sh->changePhase(ScreenPhase::PLAYING);
    }else if(this->Bsettings.getMarked()){
        this->sh->changePhase(ScreenPhase::SETTINGS);
    }
}

void Menu::update(sf::Time dt, sf::Vector2f pos){
    if(this->Bplay.check(pos)){
        this->Bplay.mark();
        this->Bsettings.unmark();
    }else if(this->Bsettings.check(pos)){
        this->Bplay.unmark();
        this->Bsettings.mark();
    }else{
        this->Bplay.unmark();
        this->Bsettings.unmark();
    }
}

void Menu::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    rt.draw(this->bg, rs);
    rt.draw(this->Bsettings, rs);
    rt.draw(this->Bplay, rs);
}
