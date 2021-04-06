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
};

class player : public ship {
public:
    player(float pos_x, float pos_y);
    void move(sf::Event event, unsigned int width, unsigned int height);
};
#endif
