#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;




class Button
{
private:
    
    
public:
    sf::Texture _texture;
    sf::Sprite btn;
    Button(){}
    Button(string path, float x_pos, float y_pos);
    ~Button();
};




#endif // BUTTON_H