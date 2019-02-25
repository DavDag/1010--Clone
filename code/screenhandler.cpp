#include "screenhandler.h"
#include "settings.h"
#include "menu.h"
#include "play.h"

ScreenHandler::ScreenHandler():
phase(ScreenPhase::MENU),
theme(sf::Color::White){

}

ScreenHandler::~ScreenHandler(){
}

sf::Color& ScreenHandler::getTheme(){
    return this->theme;
}

void ScreenHandler::update(sf::Time dt, sf::Vector2f pos){
    switch(this->phase){
        case ScreenPhase::MENU:
            this->menu->update(dt, pos);
            break;
        case ScreenPhase::SETTINGS:
            this->settings->update(dt, pos);
            break;
        case ScreenPhase::PLAYING:
            this->play->update(dt, pos);
            break;
        default:
            break;
    }
}

void ScreenHandler::changePhase(ScreenPhase::Phase sp){
    this->phase = sp;
}

void ScreenHandler::click(sf::Vector2f pos){
    switch(this->phase){
        case ScreenPhase::MENU:
            this->menu->click(pos);
            break;
        case ScreenPhase::SETTINGS:
            this->settings->click(pos);
            break;
        case ScreenPhase::PLAYING:
            this->play->click(pos);
            break;
        default:
            break;
    }
}

void ScreenHandler::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    switch(this->phase){
        case ScreenPhase::MENU:
            rt.draw(*this->menu, rs);
            break;
        case ScreenPhase::SETTINGS:
            rt.draw(*this->settings, rs);
            break;
        case ScreenPhase::PLAYING:
            rt.draw(*this->play, rs);
            break;
        default:
            break;
    }
}
