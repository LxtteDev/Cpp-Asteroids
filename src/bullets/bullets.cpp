#include "bullets.h"

Bullets::Bullets(sf::Texture texture, Window& window): mTexture(texture), mWindow(window) {};

void Bullets::update(float deltaTime) {
    for (int i = 0; i < this->bullets.size(); i++) {
        Bullet& bullet = this->bullets[i];
        if (bullet.draw(deltaTime, this->mWindow))
            this->bullets.erase(this->bullets.begin() + i);
    }
}

void Bullets::fire(sf::Sprite player) {
    sf::Vector2f position(player.getPosition());
    float rotation(player.getRotation());

    sf::Sprite sprite(this->mTexture);

    float bulletSize = (float)12/512;
    sprite.setScale(bulletSize, bulletSize);
    
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);

    sprite.setPosition(position);
    sprite.setRotation(rotation);

    Bullet bullet(sprite);

    this->bullets.push_back(bullet);
}
