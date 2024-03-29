#ifndef CONFIG_H
#define CONFIG_H
#include "system.h"
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;

class Config
{
private:
    std::unordered_map<string, std::shared_ptr<sf::Texture>> _texture_map;
    std::unordered_map<int, std::shared_ptr<sf::Font>> _font_map;
    std::shared_ptr<sf::Font> _get_font(int key);
    std::shared_ptr<sf::Texture> _get_texture(string key);
    void _set_texture();
    void _set_font();

    // load texture helper
    void _load_texture_helper();

public:
    Config();
    ~Config();
    void draw_constants(sf::RenderWindow& window, bool exclude = true);
    sf::Texture& get_texture(string index);
    sf::Font& get_font(int index);
};

// global instance here
extern Config config;

#endif