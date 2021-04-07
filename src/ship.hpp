#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdbool.h>
#include <unistd.h>
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
    void init();
    void shoot(float pos_x, float pos_y);
};

class ship {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Texture texture_fire;
    sf::Texture texture_exhaust;
    sf::Texture texture_exhaust_fire;
    sf::Sprite sprite; // спрайт корабля
    sf::Clock clock; // время пройденное с обнуления таймера
    float speed; // скорость корабля
    bool cooldown; // заряжено?
    float cooldown_time; // время перезарядки
    int count_ammo; // количество боеприпасов на корабле
    ///////////////////////
    int countbul; // для отрисовки
    bullet bul[5]; // пули для отрисовки

public:
    ship();
    ~ship();
};

class player : public ship {
public:
    player(float pos_x, float pos_y);
    void move(sf::Event event, unsigned int width, unsigned int height);
    void fire(sf::Event event);
    void check_cooldown();
};

class asteroid {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    bool life;
public:
    void init(float pos_x, float pos_y);
    void move();
};

#endif
