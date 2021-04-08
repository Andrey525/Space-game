#include <SFML/Audio.hpp>
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
    sf::Texture texture_exhaust;
    sf::Sprite sprite; // спрайт корабля
    sf::Clock clock; // время пройденное с обнуления таймера
    float speed; // скорость корабля
    bool cooldown; // заряжено?
    float cooldown_time; // время перезарядки
    int count_ammo; // количество боеприпасов на корабле
    ///////////////////////
    int countbul; // для отрисовки
    bullet* bul[5]; // пули для отрисовки

public:
    ship();
    ~ship();
    void check_cooldown();
};

class player : public ship {
public:
    int energy; // грубо говоря здоровье

    sf::SoundBuffer buffer;
    sf::Sound sound_gun;

public:
    player(float pos_x, float pos_y);
    void move(sf::Event event, unsigned int width, unsigned int height);
    void fire();
};

// class enemy : public ship {
// public:
//     enemy(float pos_x, float pos_y);
//     void move(unsigned int width, unsigned int height);
//     void fire();
// };

class danger {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    bool life;
    sf::Clock clock_buh;
    float angel;

    sf::SoundBuffer buffer;
    sf::Sound sound_bum;

public:
    danger();
    virtual void init(float pos_x, float pos_y) = 0;
    virtual void move();
    virtual void contact() = 0;
    virtual void reinit();
};

class asteroid : public danger {

public:
    asteroid();
    void init(float pos_x, float pos_y) override;
    // void move();
    void contact() override;
    // void reinit();
};

class bomb : public danger {

public:
    bomb();
    void init(float pos_x, float pos_y) override;
    // void move();
    void contact() override;
    // void reinit();
};

#endif
