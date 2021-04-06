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
    int countbul = 4;
    bullet bul[countbul];

    sf::Clock clock;
    sf::Time cooldown_time = sf::seconds(0.5f);
    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (hero_ship->cooldown == false) {
            if (clock.getElapsedTime().asSeconds() > cooldown_time.asSeconds()) {
                hero_ship->cooldown = true;
            }
        }

        for (int i = 0; i < countbul; i++) {
            if (bul[i].life == true) {
                bul[i].move();
            }
        }

        hero_ship->move(event, width, height);

        for (int i = 0; i < countbul; i++) {
            if (bul[i].life == false && hero_ship->cooldown == true) {
                hero_ship->fire(event, &bul[i]);
                clock.restart();
            }
        }
        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(hero_ship->sprite);

        for (int i = 0; i < countbul; i++) {
            if (bul[i].life == true) {
                window.draw(bul[i].sprite);
            }
        }
        window.display();
    }

    return 0;
}
