#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdbool.h>
using namespace std;

#ifndef SHIP_HPP
#define SHIP_HPP

class bullet {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    bool life;

public:
    bullet();
    ~bullet();
    bullet(float pos_x, float pos_y);
    void move();
    void init(float pos_x, float pos_y);
};

class ship {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Texture texture_fire;
    sf::Texture texture_exhaust;
    sf::Texture texture_exhaust_fire;
    sf::Sprite sprite;
    float speed;

public:
    ship();
    ~ship();
};

class player : public ship {
public:
    player(float pos_x, float pos_y);
    void move(sf::Event event, unsigned int width, unsigned int height);
    void fire(sf::Event event, bullet* bul);
};

#endif
