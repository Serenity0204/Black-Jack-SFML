#ifndef CARD_H
#define CARD_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
using namespace std;


class Card
{
private:
    static Config _config;
    string _suit;
    int _rank;
    sf::Sprite _card;
    string get_card_hash();
public:
    Card();
    Card(string suit, int rank);
    ~Card();
    sf::Sprite& get_card();
    
};


#endif