#include "asteroid.h"

Asteroid::Asteroid(sf::Sprite sprite, sf::Vector2f playerPos): mSprite(sprite) {
    sf::Vector2f velocity = playerPos - this->mSprite.getPosition();
    velocity = sf::Vector2f(sgn(velocity.x), sgn(velocity.y));

    sf::Vector2f mVelocity(velocity.x * asteroidSpeed, velocity.y * asteroidSpeed);
    this->velocity = mVelocity;

    std::cout << mVelocity.x << ", " << mVelocity.y << std::endl;
}

void Asteroid::draw(float deltaTime, Window &window) {
    sf::Vector2f position = this->mSprite.getPosition() + (this->velocity * deltaTime);

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
