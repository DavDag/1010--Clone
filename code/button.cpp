#include "button.h"
#include "textureholder.h"
#include "fontholder.h"

Button::Button(int width, int height, std::string name):
sprite(),
marked(false){
    this->text.setFont(fontsholder.get(Fonts::RobotoCondensed_Regular));
    this->text.setString(name);
    this->text.move(width / 10, 0);
    this->sprite.setTexture(textureholder.get(Textures::RedButton));
    this->scale(width / this->sprite.getGlobalBounds().width, height / this->sprite.getGlobalBounds().height);
}

bool Button::check(sf::Vector2f pos){
    sf::FloatRect rect = this->sprite.getGlobalBounds();
    rect.left += getPosition().x;
    rect.top += getPosition().y;
    rect.width *= getScale().x;
    rect.height *= getScale().y;
    return rect.contains(pos);
}

void Button::mark(){
    if(this->marked) return;
    this->marked = true;
    this->sprite.setTexture(textureholder.get(Textures::RedButtonSelected));
}

void Button::unmark(){
    if(!this->marked) return;
    this->marked = false;
    this->sprite.setTexture(textureholder.get(Textures::RedButton));
}

bool Button::getMarked(){
    return this->marked;
}

void Button::scaleText(sf::Vector2f Scale){
    this->text.scale(Scale);
}

void Button::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    rt.draw(this->sprite, rs);
    rt.draw(this->text, rs);
}
