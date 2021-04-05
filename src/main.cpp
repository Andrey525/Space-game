#include "ship.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space game");
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    window.setPosition(sf::Vector2i(300, 50));

    ship* hero_ship = new ship(400.0, 500.0);

    while (window.isOpen()) {
        hero_ship->position = hero_ship->sprite.getPosition();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                if (hero_ship->position.x > (0 + hero_ship->origin.x)) {
                    hero_ship->sprite.move(sf::Vector2f(-0.12f, 0)); // offset relative to the current position
                }
            }
            if (event.key.code == sf::Keyboard::Right) {
                if (hero_ship->position.x < (width - hero_ship->origin.x)) {
                    hero_ship->sprite.move(sf::Vector2f(0.12f, 0)); // offset relative to the current position
                }
            }
            if (event.key.code == sf::Keyboard::Up) {
                hero_ship->sprite.setTexture(hero_ship->texture_exhaust);
                if (hero_ship->position.y > (0 + hero_ship->origin.y)) {
                    hero_ship->sprite.move(sf::Vector2f(0, -0.18f)); // offset relative to the current position
                }
            }
            if (event.key.code == sf::Keyboard::Down) {
                if (hero_ship->position.y < (height - (hero_ship->origin.y - 60))) {
                    hero_ship->sprite.move(sf::Vector2f(0, 0.08f)); // offset relative to the current position
                }
            }
        }

        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                hero_ship->sprite.setTexture(hero_ship->texture);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(hero_ship->sprite);
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
