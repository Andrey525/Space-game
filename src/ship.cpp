#include "ship.hpp"
#include <iostream>

ship::ship()
{
}

ship::~ship()
{
}

ship::ship(float pos_x, float pos_y)
{
    if (!texture.loadFromFile("../img/spaceship2.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }
    if (!texture_exhaust.loadFromFile("../img/spaceship2_2.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(80.f, 100.f));
    origin = sprite.getOrigin();
    sprite.setPosition(sf::Vector2f(pos_x, pos_y)); // absolute position
}