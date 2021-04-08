#include "classes.hpp"

danger::danger()
{
}

void danger::move()
{
    this->position = this->sprite.getPosition();
    if (this->position.y < 600) { // двигаемся пока не врежемся в нижнюю стенку
        this->sprite.move(sf::Vector2f(0, 1 * this->speed));
        this->sprite.rotate(angel * 0.1);
    } else if (this->speed != 0) {
        // this->life = false; // врезались в стенку
        // this->speed = 0;
        this->contact();
    }
}

void danger::reinit()
{
    if (this->speed == 0) {
        if (this->clock_buh.getElapsedTime().asSeconds() > 0.1) {
            this->life = false;
            this->init(100 + rand() % 1200, -500 + rand() % 500);
        }
    }
}

asteroid::asteroid()
{
    texture.loadFromFile("img/asteroid.png");
    sprite.setTexture(this->texture);
    speed = 0.1;
    sprite.setOrigin(sf::Vector2f(this->texture.getSize().x / 2, this->texture.getSize().y / 2));
    origin = sprite.getOrigin();
}

void asteroid::init(float pos_x, float pos_y)
{
    int flag = rand() % 2;
    if (flag == 0) {
        this->texture.loadFromFile("img/asteroid.png");
    } else {
        this->texture.loadFromFile("img/asteroid2.png");
    }

    this->sprite.setTexture(this->texture);
    this->speed = 0.1;
    flag = rand() % 2;
    if (flag == 0) {
        this->angel = 1;
    } else {
        this->angel = -1;
    }
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->life = true;
}

void asteroid::contact()
{
    this->texture.loadFromFile("img/bum.png");
    this->sprite.setTexture(this->texture);
    this->speed = 0;
    this->clock_buh.restart();
}

bomb::bomb()
{
    texture.loadFromFile("img/bomb.png");
    sprite.setTexture(this->texture);
    sprite.setColor(sf::Color(180, 180, 180));
    speed = 0.07;
    sprite.setOrigin(sf::Vector2f(this->texture.getSize().x / 2, this->texture.getSize().y / 2));
    origin = sprite.getOrigin();
}

void bomb::init(float pos_x, float pos_y)
{
    int flag = rand() % 2;
    this->texture.loadFromFile("img/bomb.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    sprite.setColor(sf::Color(180, 180, 180));
    this->speed = 0.07;
    flag = rand() % 2;
    if (flag == 0) {
        this->angel = 0.5;
    } else {
        this->angel = -0.5;
    }
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->life = true;
}

void bomb::contact()
{
    this->texture.loadFromFile("img/bomb_bum.png");
    this->sprite.setTexture(this->texture);
    sprite.setColor(sf::Color(255, 255, 255));
    this->speed = 0;
    this->clock_buh.restart();
}
