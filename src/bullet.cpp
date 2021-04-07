#include "ship.hpp"
#include <iostream>
bullet::bullet()
{
}

bullet::~bullet()
{
}

bullet::bullet(float pos_x, float pos_y)
{
    this->texture.loadFromFile("img/bullet.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->speed = 0.5;
    sprite.setOrigin(sf::Vector2f(10.0f, 17.5f));
    this->origin = sprite.getOrigin();
    this->life = true;
}

void bullet::move()
{
    this->position = this->sprite.getPosition();
    if (this->position.y > 0) { // двигаемся пока не врежемся в верхнюю стенку
        this->sprite.move(sf::Vector2f(0, -1 * this->speed));
    } else {
        this->life = false; // врезались в стенку - пуля мертва
    }
}

void bullet::init()
{
    this->texture.loadFromFile("img/bullet.png");
    this->sprite.setTexture(this->texture);
    this->speed = 1;
    sprite.setOrigin(sf::Vector2f(10.0f, 17.5f));
    this->origin = sprite.getOrigin();
    this->life = false;
}

void bullet::shoot(float pos_x, float pos_y) // когда выстрелили
{
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y)); // задаем начальную позицию (нос корабля)
    this->life = true; // оживляем
}
