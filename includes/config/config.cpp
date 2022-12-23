#include "config.h"



Config::Config()
{
    this->_set_texture();
    this->_set_font();
}

Config::~Config(){}


std::shared_ptr<sf::Texture> Config::_get_texture(string key)
{
    if(this->_texture_map.find(key) != this->_texture_map.end()) 
    {
        return this->_texture_map[key];
    }
    return nullptr;
}

std::shared_ptr<sf::Font> Config::_get_font(int key)
{
    if(this->_font_map.find(key) != this->_font_map.end()) 
    {
        return this->_font_map[key];
    }
    return nullptr;
}



sf::Texture& Config::get_texture(string index)
{
    std::shared_ptr<sf::Texture> texture = this->_get_texture(index);
    assert(texture != nullptr && "Getting non existed texture");
    return *texture;
}


sf::Font& Config::get_font(int index)
{
    std::shared_ptr<sf::Font> font = this->_get_font(index);
    assert(font != nullptr && "Getting non existed font");
    return *font;
}




void Config::_set_texture()
{
    // set texture example

    for(int i = 0; i < 13; ++i)
    {
        string temp = "";

        // get the substring path
        switch (i)
        {
        case 0:
            temp += "ace";
            break;
        case 10:
            temp += "jack";
            break;
        case 11:
            temp += "queen";
            break;
        case 12:
            temp += "king";
            break;
        default:
            temp += to_string(i + 1);
            break;
        }

        string clubs = PATH + temp + CLUBS;
        auto club_ptr = std::make_shared<sf::Texture>();
        club_ptr->loadFromFile(clubs);

        string club_hash = "c" + to_string(i + 1);
        this->_texture_map[club_hash] = club_ptr;
   

        string diamonds = PATH + temp + DIAMONDS;
        auto diamond_ptr = std::make_shared<sf::Texture>();
        diamond_ptr->loadFromFile(clubs);
        string diamond_hash = "d" + to_string(i + 1);
        this->_texture_map[diamond_hash] = diamond_ptr;


        string hearts = PATH + temp + HEARTS;
        auto heart_ptr = std::make_shared<sf::Texture>();
        heart_ptr->loadFromFile(clubs);
        string heart_hash = "h" + to_string(i + 1);
        this->_texture_map[heart_hash] = heart_ptr;

        string spades = PATH + temp + SPADES;
        auto spade_ptr = std::make_shared<sf::Texture>();
        spade_ptr->loadFromFile(clubs);
        string spade_hash = "s" + to_string(i + 1);
        this->_texture_map[spade_hash] = spade_ptr;
    
    }
}

void Config::_set_font()
{
    // set font example
    
    auto f1 = std::make_shared<sf::Font>();
    f1->loadFromFile("../assets/arial.ttf");
    this->_font_map[ARIAL] = f1;
}