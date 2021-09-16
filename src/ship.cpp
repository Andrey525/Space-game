#include "classes.hpp"

extern std::ostringstream playerEnergyString;

ship::ship()
{
}

ship::~ship()
{
}

void ship::setspeed(float speed)
{
    this->speed = speed;
}

float ship::getspeed()
{
    return this->speed;
}

void ship::setcooldown(bool cooldown)
{
    this->cooldown = cooldown;
}

bool ship::getcooldown()
{
    return this->cooldown;
}

void ship::setcooldown_time(float cooldown_time)
{
    this->cooldown_time = cooldown_time;
}

float ship::getcooldown_time()
{
    return this->cooldown_time;
}

void ship::setcount_ammo(int count_ammo)
{
    this->count_ammo = count_ammo;
}

int ship::getcount_ammo()
{
    return this->count_ammo;
}

void player::setenergy(int energy)
{
    this->energy = energy;
    playerEnergyString.str("");
    playerEnergyString << this->getenergy();
}

int player::getenergy()
{
    return this->energy;
}

void ship::check_cooldown()
{
    if (this->cooldown == false && this->count_ammo != 0) {
        if (this->clock.getElapsedTime().asSeconds() > this->cooldown_time) {
            this->cooldown = true;
        }
    }
    // else if (this->cooldown == false && this->count_ammo == 0) { // если выстрелили и не осталось боеприпасов, обнуляем время
    //     clock.restart(); // для того, чтоб, если словили коробку с боезапасом, у нас не сразу было заряжено оружие, а происходила перезарядка
    // }
}

player::player(float pos_x, float pos_y)
{
    if (!texture.loadFromFile("img/spaceship2.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }

    if (!texture_exhaust.loadFromFile("img/spaceship2_2.png")) {
        cout << "Ошибка загрузки текстуры" << endl;
    }

    buffer.loadFromFile("sound/gun.wav");
    sound_gun.setBuffer(buffer);
    sound_gun.setVolume(50.f);
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(this->texture.getSize().x / 2, this->texture.getSize().y / 2));
    origin = sprite.getOrigin();
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    setspeed(1.0);
    setcooldown(true);
    setcount_ammo(1000);
    setcooldown_time(0.5);
    countbul = 5;
    for (int i = 0; i < countbul; i++) {
        bul[i] = new bullet();
    }
    energy = 3;
}

void player::move(sf::Event event, unsigned int width, unsigned int height)
{
    this->position = this->sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (this->position.x > (0 + this->origin.x)) {
            this->sprite.move(sf::Vector2f(-3 * this->getspeed(), 0));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (this->position.x < (width - this->origin.x)) {
            this->sprite.move(sf::Vector2f(3 * this->getspeed(), 0));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->sprite.setTexture(this->texture_exhaust);
        if (this->position.y > (0 + this->origin.y)) {
            this->sprite.move(sf::Vector2f(0, -5 * this->getspeed()));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->position.y < (height - (this->origin.y))) {
            this->sprite.move(sf::Vector2f(0, 2 * this->getspeed()));
        }
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) {
            this->sprite.setTexture(this->texture);
        }
    }

    if (this->position.y < (height - (this->origin.y))) {
        this->sprite.move(sf::Vector2f(0, 0.7f));
    }
}

void player::fire()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        for (int i = 0; i < countbul; i++) {
            if (this->getcount_ammo() > 0 && this->bul[i]->getBullife() == false && this->getcooldown() == true) { // могу выстрелить
                this->position = this->sprite.getPosition();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { // стреляю в движении вверх (когда сопла работают)
                    this->bul[i]->shoot(position.x, position.y - 60);
                    this->sound_gun.play();
                    this->setcount_ammo(this->getcount_ammo() - 1);
                    this->setcooldown(false); // разряжено
                    this->clock.restart(); // начинаем заново отчет времени
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 0) { // стреляю в остальных случаях
                    this->bul[i]->shoot(position.x, position.y - 60);
                    this->sound_gun.play();
                    this->setcount_ammo(this->getcount_ammo() - 1);
                    this->setcooldown(false);
                    this->clock.restart();
                }
            }
        }
    }
}
