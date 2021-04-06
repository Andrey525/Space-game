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
    if (!texture.loadFromFile("img/bullet.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }
    sprite.setTexture(texture);
    // sprite.setOrigin(sf::Vector2f(80.f, 100.f));
    // origin = sprite.getOrigin();
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    speed = 0.5;
}

void bullet::move()
{
    this->position = this->sprite.getPosition();
    if (this->position.y > 0) {
        this->sprite.move(sf::Vector2f(0, -1 * this->speed));
    } else {
        this->life = false;
    }
}

void bullet::init(float pos_x, float pos_y)
{
    this->texture.loadFromFile("img/bullet.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->speed = 0.5;
    sprite.setOrigin(sf::Vector2f(10.0f, 17.5f));
    this->origin = sprite.getOrigin();
    this->life = true;
}