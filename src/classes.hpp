#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
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

private:
    float speed;
    bool life;

public:
    bullet();
    ~bullet();
    bullet(float pos_x, float pos_y);
    void setBullife(bool alive);
    bool getBullife();
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

private:
    float speed; // скорость корабля
    bool cooldown; // заряжено?
    float cooldown_time; // время перезарядки
    int count_ammo; // количество боеприпасов на корабле

public:
    int countbul; // для отрисовки
    bullet* bul[5]; // пули для отрисовки

public:
    ship();
    ~ship();
    void setspeed(float speed);
    float getspeed();
    void setcooldown(bool cooldown);
    bool getcooldown();
    void setcooldown_time(float cooldown_time);
    float getcooldown_time();
    void setcount_ammo(int count_ammo);
    int getcount_ammo();
    void check_cooldown();
};

class player : public ship {
public:
    sf::SoundBuffer buffer;
    sf::Sound sound_gun;

private:
    int energy; // грубо говоря здоровье

public:
    void setenergy(int energy);
    int getenergy();
    player(float pos_x, float pos_y);
    void move(sf::Event event, unsigned int width, unsigned int height);
    void fire();
};

class danger {
public:
    sf::Vector2f position;
    sf::Vector2f origin;
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Clock clock_buh;

    sf::SoundBuffer buffer;
    sf::Sound sound_bum;

private:
    float speed;
    bool life;
    float angel;
    int damage;

public:
    danger();
    void setlife(bool alive);
    bool getlife();
    void setspeed(float speed);
    float getspeed();
    void setangel(float angel);
    float getangel();
    void setdamage(int damage);
    int getdamage();

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
