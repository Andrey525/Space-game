#include "classes.hpp"

extern int liner_energy;
extern std::ostringstream linerEnergyString;
extern int game;
extern sf::Text text5;

danger::danger()
{
    buffer.loadFromFile("sound/bum.wav");
    sound_bum.setBuffer(buffer);
    sound_bum.setVolume(50.f);
}

void danger::setlife(bool alive)
{
    this->life = alive;
}

bool danger::getlife()
{
    return this->life;
}

void danger::setspeed(float speed)
{
    this->speed = speed;
}

float danger::getspeed()
{
    return this->speed;
}

void danger::setangel(float angel)
{
    this->angel = angel;
}

float danger::getangel()
{
    return this->angel;
}

void danger::setdamage(int damage)
{
    this->damage = damage;
}

int danger::getdamage()
{
    return this->damage;
}

void danger::move()
{
    this->position = this->sprite.getPosition();
    if (this->position.y < 600) { // двигаемся пока не врежемся в нижнюю стенку
        this->sprite.move(sf::Vector2f(0, 1 * this->speed));
        this->sprite.rotate(angel * 0.1);
    } else if (this->getspeed() != 0) {
        this->contact();
        liner_energy = liner_energy - this->getdamage();
        linerEnergyString.str("");
        linerEnergyString << liner_energy;
        if (liner_energy <= 0) {
            text5.setString("GAME OVER!");
            text5.setPosition(540, 150);
            text5.setFillColor(sf::Color::Red);
            game = -1;
        }
    }
}

void danger::reinit()
{
    if (this->getspeed() == 0) {
        if (this->clock_buh.getElapsedTime().asSeconds() > 0.1) {
            this->setlife(false);
            this->init(100 + rand() % 1200, -500 + rand() % 500);
        }
    }
}

asteroid::asteroid()
{
    texture.loadFromFile("img/asteroid.png");
    sprite.setTexture(this->texture);
    setspeed(0.1);
    sprite.setOrigin(sf::Vector2f(this->texture.getSize().x / 2, this->texture.getSize().y / 2));
    origin = sprite.getOrigin();
    setdamage(1);
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
    this->setspeed(0.8);
    flag = rand() % 2;
    if (flag == 0) {
        this->setangel(7);
    } else {
        this->setangel(-7);
    }
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->setlife(true);
}

void asteroid::contact()
{
    this->sound_bum.play();
    this->texture.loadFromFile("img/bum.png");
    this->sprite.setTexture(this->texture);
    this->setspeed(0);
    this->clock_buh.restart();
}

bomb::bomb()
{
    texture.loadFromFile("img/bomb.png");
    sprite.setTexture(this->texture);
    sprite.setColor(sf::Color(180, 180, 180));
    setspeed(0.07);
    sprite.setOrigin(sf::Vector2f(this->texture.getSize().x / 2, this->texture.getSize().y / 2));
    origin = sprite.getOrigin();
    setdamage(2);
}

void bomb::init(float pos_x, float pos_y)
{
    int flag = rand() % 2;
    this->texture.loadFromFile("img/bomb.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    sprite.setColor(sf::Color(180, 180, 180));
    this->setspeed(0.6);
    flag = rand() % 2;
    if (flag == 0) {
        this->setangel(3.5);
    } else {
        this->setangel(-3.5);
    }
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    this->setlife(true);
}

void bomb::contact()
{
    this->sound_bum.play();
    this->texture.loadFromFile("img/bomb_bum.png");
    this->sprite.setTexture(this->texture);
    sprite.setColor(sf::Color(255, 255, 255));
    this->setspeed(0);
    this->clock_buh.restart();
}
