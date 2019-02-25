#include "tile.h"

Tile::Tile(){
}

Tile::Tile(int width, int height, int i, int j):
x(i),
y(j),
sprite(),
marked(false),
animated(false),
color(Pieces::Color::Empty){
    this->tmx = sf::milliseconds(250);
    this->sprite.setTexture(textureholder.get(Textures::EmptyBlock));
    this->scale(width / this->sprite.getGlobalBounds().width, height / this->sprite.getGlobalBounds().height);
    this->move(width * i, height * j);
}

Pieces::Color Tile::getColor(){
    return this->color;
}

bool Tile::getAnimated(){
    return this->animated;
}

void Tile::animate(){
    this->animated = true;
    this->trim = this->tmx;
}

void Tile::update(sf::Time dt){
    if(this->animated){
        this->trim -= dt;
        this->sprite.setScale(this->trim.asSeconds() / this->tmx.asSeconds(), this->trim.asSeconds() / this->tmx.asSeconds());
        this->sprite.setPosition((50.f - this->sprite.getScale().x * 50.f) / 2, (50.f - this->sprite.getScale().y * 50.f) / 2);
        if(this->trim.asMilliseconds() <= 0){
            this->sprite.setPosition(0, 0);
            this->sprite.setScale(1, 1);
            this->setColor(Pieces::Color::Empty);
            this->animated = false;
        }
    }
}

void Tile::setColor(Pieces::Color c){
    switch(c){
        case Pieces::Color::Red:
            this->sprite.setTexture(textureholder.get(Textures::RedBlock), true);
            break;
        case Pieces::Color::Blue:
            this->sprite.setTexture(textureholder.get(Textures::BlueBlock), true);
            break;
        case Pieces::Color::LightBlue:
            this->sprite.setTexture(textureholder.get(Textures::LightBlueBlock), true);
            break;
        case Pieces::Color::Orange:
            this->sprite.setTexture(textureholder.get(Textures::OrangeBlock), true);
            break;
        case Pieces::Color::Green:
            this->sprite.setTexture(textureholder.get(Textures::GreenBlock), true);
            break;
        case Pieces::Color::DarkGreen:
            this->sprite.setTexture(textureholder.get(Textures::DarkGreenBlock), true);
            break;
        case Pieces::Color::Empty:
            this->sprite.setTexture(textureholder.get(Textures::EmptyBlock), true);
            break;
        default:
            break;
    }
    this->color = c;
}

sf::FloatRect Tile::getGlobalBounds(){
    sf::FloatRect rect = this->sprite.getGlobalBounds();
    rect.left += getPosition().x;
    rect.top += getPosition().y;
    rect.width *= getScale().x;
    rect.height *= getScale().y;
    return rect;
}

bool Tile::check(sf::Vector2f pos){
    return this->getGlobalBounds().contains(pos);
}

int Tile::getWidth(){
    return this->getScale().x * this->sprite.getGlobalBounds().width;
}

int Tile::getHeight(){
    return this->getScale().y * this->sprite.getGlobalBounds().height;
}

bool Tile::isLefter(sf::Vector2f pos){
    return pos.x < (this->getGlobalBounds().left + this->getGlobalBounds().width / 2);
}

bool Tile::isUpper(sf::Vector2f pos){
    return pos.y < (this->getGlobalBounds().top + this->getGlobalBounds().height / 2);
}

void Tile::mark(){
    if(this->marked) return;
    this->marked = true;
    this->sprite.setColor(sf::Color(224, 224, 224));
}

void Tile::suggest(bool sgg){
    if(sgg) this->sprite.setColor(sf::Color(192, 192, 192));
    else this->sprite.setColor(sf::Color::White);
}

void Tile::unmark(){
    if(!this->marked) return;
    this->marked = false;
    this->sprite.setColor(sf::Color::White);
}

bool Tile::getMarked(){
    return this->marked;
}

bool Tile::isEmpty(){
    return this->color == Pieces::Color::Empty || this->animated;
}

void Tile::draw(sf::RenderTarget& rt, sf::RenderStates rs) const{
    rs.transform *= getTransform();
    rs.texture = NULL;
    rt.draw(this->sprite, rs);
}
