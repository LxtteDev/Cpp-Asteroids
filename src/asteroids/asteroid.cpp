#include "asteroid.h"

Asteroid::Asteroid(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool type): mSprite(sprite), mVelocity(velocity), mType(type) {
    this->mSprite.setPosition(position);
}

void Asteroid::draw(float deltaTime, Window &window) {
    sf::Vector2f position = this->mSprite.getPosition() + (this->mVelocity * deltaTime);

    if (position.x > 500)
        position.x = 0; 
    else if (position.x < 0)
        position.x = 500;

    if (position.y > 500)
        position.y = 0; 
    else if (position.y < 0)
        position.y = 500;

    // std::cout << position.x << ", " << position.y << "\r" << std::flush;

    this->mSprite.setPosition(position);
    window.draw(this->mSprite);
}

sf::FloatRect Asteroid::bounds() {
    return this->mSprite.getGlobalBounds();
}
