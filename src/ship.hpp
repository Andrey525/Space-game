#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

#ifndef SHIP_HPP
#define SHIP_HPP

class ship {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Texture texture_exhaust;
    sf::Sprite sprite;

public:
    ship();
    ~ship();
    ship(float pos_x, float pos_y);
};
#endif
