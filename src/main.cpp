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

    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        hero_ship->move(event, width, height);
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
