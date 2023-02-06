#include "asteroid.h"

Asteroid::Asteroid(sf::Sprite sprite, sf::Vector2f playerPos): mSprite(sprite) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 500);

    int x = dis(gen);
    int y = dis(gen);

    if (x >= y)
        y = std::floor(y / 500 + 0.5);
    else if (y >= x)
        x = std::floor(x / 500 + 0.5);

    this->mSprite.setPosition(sf::Vector2f(x, y));
    sf::Vector2f velocity = playerPos - this->mSprite.getPosition();
    velocity = sf::Vector2f(velocity.x / 500, velocity.y / 500);

    sf::Vector2f mVelocity(velocity.x * asteroidSpeed, velocity.y * asteroidSpeed);
    this->velocity = mVelocity;
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

sf::FloatRect Asteroid::bounds() {
    return this->mSprite.getGlobalBounds();
}
