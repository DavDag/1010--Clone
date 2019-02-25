#include "textureholder.h"

TextureHolder::TextureHolder(){
    this->load(Textures::RedButton,         "assets/UI/red_button00.png");
    this->load(Textures::RedButtonSelected, "assets/UI/red_button01.png");
    this->load(Textures::BlueButton,        "assets/UI/blue_button00.png");
    this->load(Textures::GreenButton,       "assets/UI/green_button00.png");
    this->load(Textures::YellowButton,      "assets/UI/yellow_button00.png");
    this->load(Textures::GreyButton,        "assets/UI/grey_button00.png");
    this->load(Textures::Background,        "assets/UI/bg.jpg");
    this->load(Textures::RedBlock,          "assets/Blocks/red.png");
    this->load(Textures::GreenBlock,        "assets/Blocks/green.png");
    this->load(Textures::BlueBlock,         "assets/Blocks/blue.png");
    this->load(Textures::DarkGreenBlock,    "assets/Blocks/darkgreen.png");
    this->load(Textures::LightBlueBlock,    "assets/Blocks/lightblue.png");
    this->load(Textures::OrangeBlock,       "assets/Blocks/orange.png");
    this->load(Textures::EmptyBlock,        "assets/Blocks/empty.png");
}

TextureHolder::~TextureHolder(){
}

void TextureHolder::load(Textures::ID id, const std::string &filename){
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);
    TextureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(Textures::ID id){
    auto found = TextureMap.find(id);
    return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id) const{
    auto found = TextureMap.find(id);
    return *found->second;
}

TextureHolder textureholder;

