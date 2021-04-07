#include "ship.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(2360, 700), "Space game");
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    window.setPosition(sf::Vector2i(0, 0));

    player* hero_ship = new player(width / 2, height - 80);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        hero_ship->check_cooldown();
        for (int i = 0; i < hero_ship->countbul; i++) {
            if (hero_ship->bul[i].life == true) {
                hero_ship->bul[i].move();
                window.draw(hero_ship->bul[i].sprite);
            }
            hero_ship->fire(event);
        }
        hero_ship->move(event, width, height);
        window.draw(hero_ship->sprite);

        window.display();
    }

    return 0;
}
