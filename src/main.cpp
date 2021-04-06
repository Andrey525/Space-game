#include "ship.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1360, 700), "Space game");
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    window.setPosition(sf::Vector2i(0, 0));

    player* hero_ship = new player(width / 2, height - 80);
    bullet bul;
    bul.life = false;
    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (bul.life == true) {
            bul.move();
        }
        hero_ship->move(event, width, height);
        hero_ship->fire(event, &bul);

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(hero_ship->sprite);
        if (bul.life == true) {
            window.draw(bul.sprite);
        }
        window.display();
    }

    return 0;
}
