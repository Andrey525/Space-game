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
    asteroid ast;
    ast.init(300, -100);
    sf::Clock clock_buh;
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
                if (hero_ship->bul[i].sprite.getGlobalBounds().intersects(ast.sprite.getGlobalBounds())) {
                    hero_ship->bul[i].life = false;
                    ast.texture.loadFromFile("img/bum.png");
                    ast.sprite.setTexture(ast.texture);
                    ast.speed = 0;
                    clock_buh.restart();
                }
            }
            hero_ship->fire(event);
        }
        hero_ship->move(event, width, height);
        window.draw(hero_ship->sprite);

        if (ast.speed == 0) {
            if (clock_buh.getElapsedTime().asSeconds() > 0.1) {
                ast.life = false;
                ast.init(100 + rand() % 1000, -100);
            }
        }
        if (ast.sprite.getGlobalBounds().intersects(hero_ship->sprite.getGlobalBounds()) == 1) {
            ast.texture.loadFromFile("img/bum.png");
            ast.sprite.setTexture(ast.texture);
            ast.speed = 0;
            clock_buh.restart();
        }
        ast.move();
        if (ast.life == true) {
            window.draw(ast.sprite);
        }

        window.display();
    }

    return 0;
}
