#include "classes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1360, 700), "Space game");
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    window.setPosition(sf::Vector2i(0, 0));

    sf::Texture texture_background;
    sf::Sprite sprite_background;
    texture_background.loadFromFile("img/background3.jpg");
    sprite_background.setTexture(texture_background);
    sprite_background.setOrigin(sf::Vector2f(texture_background.getSize().x / 2, texture_background.getSize().y / 2));
    sprite_background.setPosition(sf::Vector2f(width / 2, height / 2));

    sf::Texture texture_liner;
    sf::Sprite sprite_liner;
    texture_liner.loadFromFile("img/liner.png");
    sprite_liner.setTexture(texture_liner);
    sprite_liner.setOrigin(sf::Vector2f(texture_liner.getSize().x / 2, texture_liner.getSize().y / 2));
    sprite_liner.setPosition(sf::Vector2f(width / 2, height - sprite_liner.getOrigin().y));

    // sf::Music music;
    // music.openFromFile("sound/ship.wav");
    // music.play();
    int liner_energy = 10;
    player* hero_ship = new player(width / 2, height - 80);
    danger* danger[5];
    for (int i = 0; i < 3; i++) {
        danger[i] = new asteroid();
        danger[i]->init(100 + rand() % 1000, -200 + rand() % 200);
    }
    for (int i = 3; i < 5; i++) {
        danger[i] = new bomb();
        danger[i]->init(100 + rand() % 1000, -200 + rand() % 200);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(sprite_liner);
        hero_ship->check_cooldown();
        for (int i = 0; i < hero_ship->countbul; i++) {
            if (hero_ship->bul[i]->life == true) {
                hero_ship->bul[i]->move();
                window.draw(hero_ship->bul[i]->sprite);
                for (int j = 0; j < 5; j++) {
                    if (hero_ship->bul[i]->sprite.getGlobalBounds().intersects(danger[j]->sprite.getGlobalBounds())) {
                        hero_ship->bul[i]->life = false;
                        danger[j]->contact();
                    }
                }
            }
            hero_ship->fire();
        }
        hero_ship->move(event, width, height);
        window.draw(hero_ship->sprite);
        for (int i = 0; i < 5; i++) {
            danger[i]->reinit();
            if (danger[i]->speed != 0 && danger[i]->sprite.getGlobalBounds().intersects(hero_ship->sprite.getGlobalBounds()) == 1) {
                danger[i]->contact();
                --hero_ship->energy;
            }
            danger[i]->move();
            if (danger[i]->life == true) {
                window.draw(danger[i]->sprite);
            }
        }

        window.display();
    }

    return 0;
}
