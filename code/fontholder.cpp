#include "fontholder.h"

FontHolder::FontHolder(){
    this->load(Fonts::RobotoCondensed_Regular, "assets/UI/RobotoCondensed-Regular.ttf");
}

FontHolder::~FontHolder(){
}

void FontHolder::load(Fonts::ID id, const std::string &filename){
    std::unique_ptr<sf::Font> font(new sf::Font());
    font->loadFromFile(filename);
    FontMap.insert(std::make_pair(id, std::move(font)));
}

sf::Font& FontHolder::get(Fonts::ID id){
    auto found = FontMap.find(id);
    return *found->second;
}

const sf::Font& FontHolder::get(Fonts::ID id) const{
    auto found = FontMap.find(id);
    return *found->second;
}

FontHolder fontsholder;


