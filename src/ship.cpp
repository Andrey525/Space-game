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
    if (!texture_fire.loadFromFile("img/spaceship2_fire.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }
    if (!texture_exhaust_fire.loadFromFile("img/spaceship2_2_fire.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(80.f, 100.f));
    origin = sprite.getOrigin();
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    speed = 0.1;
    cooldown = true;
}

void player::move(sf::Event event, unsigned int width, unsigned int height)
{
    this->position = this->sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (this->position.x > (0 + this->origin.x)) {
            this->sprite.move(sf::Vector2f(-3 * speed, 0));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (this->position.x < (width - this->origin.x)) {
            this->sprite.move(sf::Vector2f(3 * speed, 0));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->sprite.setTexture(this->texture_exhaust);
        if (this->position.y > (0 + this->origin.y)) {
            this->sprite.move(sf::Vector2f(0, -5 * speed));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->position.y < (height - (this->origin.y))) {
            this->sprite.move(sf::Vector2f(0, 2 * speed));
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            this->sprite.setTexture(this->texture);
        }
    }

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 0) {
    if (this->position.y < (height - (this->origin.y))) {
        this->sprite.move(sf::Vector2f(0, 0.1f));
    }
    // }
}

void player::fire(sf::Event event, bullet* bul)
{
    this->position = this->sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        // this->sprite.setTexture(this->texture_exhaust_fire);
        bul->init(position.x - 10, position.y - 60);
        this->cooldown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 0) {
        // this->sprite.setTexture(this->texture_fire);
        bul->init(position.x - 10, position.y - 60);
        this->cooldown = false;
    }
    // if (event.type == sf::Event::KeyReleased) {
    // if (event.key.code == sf::Keyboard::F && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 0) {
    // this->sprite.setTexture(this->texture);
    // }
    // }
}
