#include "ship.hpp"

void asteroid::init(float pos_x, float pos_y)
{
    this->texture.loadFromFile("img/asteroid.png");
    this->sprite.setTexture(this->texture);
    this->speed = 0.2;
    sprite.setOrigin(sf::Vector2f(24.0f, 24.0f));
    this->origin = sprite.getOrigin();
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->life = true;
}

void asteroid::move()
{
    this->position = this->sprite.getPosition();
    if (this->position.y < 760) { // двигаемся пока не врежемся в нижнюю стенку
        this->sprite.move(sf::Vector2f(0, 1 * this->speed));
        this->sprite.rotate(-0.1);
    } else {
        this->life = false; // врезались в стенку
        this->speed = 0;
    }
}