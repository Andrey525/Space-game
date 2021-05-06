#include "classes.hpp"

int liner_energy = 10;
std::ostringstream playerEnergyString, linerEnergyString, scoreString;
int score = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1360, 700), "Space game");
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    window.setPosition(sf::Vector2i(0, 0));
    window.setVerticalSyncEnabled(true);
    // window.setFramerateLimit(60);

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

    sf::Music music;
    music.openFromFile("sound/music.wav");
    music.play();
    music.setLoop(true);

    sf::Font font;
    font.loadFromFile("font/stencil.ttf");
    sf::Text text, text2, text3, text4;
    // text.setFont(font);
    // text.setString("Approach to danger");
    // text.setCharacterSize(64);
    // text.setFillColor(sf::Color::White);
    // text.setPosition(100, 100);
    text2.setFont(font);
    text2.setCharacterSize(32);
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(0, 30);
    text3.setFont(font);
    text3.setCharacterSize(32);
    text3.setFillColor(sf::Color::Red);
    text3.setPosition(0, 60);
    text4.setFont(font);
    text4.setCharacterSize(32);
    text4.setFillColor(sf::Color::Yellow);
    text4.setPosition(0, 90);

    player* hero_ship = new player(width / 2, height - 80);
    playerEnergyString << hero_ship->getenergy();
    linerEnergyString << liner_energy;
    scoreString << score;
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
        text2.setString("Ship energy: " + playerEnergyString.str());
        text3.setString("Liner energy: " + linerEnergyString.str());
        text4.setString("Score: " + scoreString.str());
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(sprite_liner);
        // window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        hero_ship->check_cooldown();
        for (int i = 0; i < hero_ship->countbul; i++) {
            if (hero_ship->bul[i]->getBullife() == true) {
                hero_ship->bul[i]->move();
                window.draw(hero_ship->bul[i]->sprite);
                for (int j = 0; j < 5; j++) {
                    if (hero_ship->bul[i]->sprite.getGlobalBounds().intersects(danger[j]->sprite.getGlobalBounds())) {
                        hero_ship->bul[i]->setBullife(false);
                        danger[j]->contact();
                        score++;
                        scoreString.str("");
                        scoreString << score;
                    }
                }
            }
            hero_ship->fire();
        }
        hero_ship->move(event, width, height);
        window.draw(hero_ship->sprite);
        for (int i = 0; i < 5; i++) {
            danger[i]->reinit();
            if (danger[i]->getspeed() != 0 && danger[i]->sprite.getGlobalBounds().intersects(hero_ship->sprite.getGlobalBounds()) == 1) {
                danger[i]->contact();
                hero_ship->setenergy(hero_ship->getenergy() - danger[i]->getdamage());
                if (hero_ship->getenergy() <= 0) {
                    cout << "Game over! Your ship is destroyed!" << endl;
                }
            }
            danger[i]->move();
            if (danger[i]->getlife() == true) {
                window.draw(danger[i]->sprite);
            }
        }
        window.display();
    }

    return 0;
}
