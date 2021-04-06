#include "ship.hpp"
#include <iostream>

ship::ship()
{
}

ship::~ship()
{
}

player::player(float pos_x, float pos_y)
{
    if (!texture.loadFromFile("img/spaceship2.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }

    if (!texture_exhaust.loadFromFile("img/spaceship2_2.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(80.f, 100.f));
    origin = sprite.getOrigin();
    sprite.setPosition(sf::Vector2f(pos_x, pos_y)); // absolute position
}

void player::move(sf::Event event, unsigned int width, unsigned int height)
{
    this->position = this->sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (this->position.x > (0 + this->origin.x)) {
            this->sprite.move(sf::Vector2f(-0.15f, 0)); // offset relative to the current position
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (this->position.x < (width - this->origin.x)) {
            this->sprite.move(sf::Vector2f(0.15f, 0)); // offset relative to the current position
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->sprite.setTexture(this->texture_exhaust);
        if (this->position.y > (0 + this->origin.y)) {
            this->sprite.move(sf::Vector2f(0, -0.45f)); // offset relative to the current position
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->position.y < (height - (this->origin.y - 60))) {
            this->sprite.move(sf::Vector2f(0, 0.12f)); // offset relative to the current position
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            this->sprite.setTexture(this->texture);
        }
    }
}