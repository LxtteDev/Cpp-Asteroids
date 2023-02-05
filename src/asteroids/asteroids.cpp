#include "asteroids.h"

Asteroids::Asteroids(sf::Texture texture, Window& window): mWindow(window) {
    this->texture = texture;
    
}

Asteroids::~Asteroids() {
}

void Asteroids::update(float deltaTime, sf::Vector2f playerPos) {
    if (this->asteroids.size() < 10)
        createAsteroid(playerPos);
    for (Asteroid& asteroid : this->asteroids) {
        asteroid.draw(deltaTime, this->mWindow); 
    }
}

void Asteroids::createAsteroid(sf::Vector2f playerPos) {
    sf::Sprite sprite(this->texture);

    float asteroidSize = (float)75/512;
    sprite.setScale(asteroidSize, asteroidSize);
    
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);

    Asteroid asteroid(sprite, playerPos);

    this->asteroids.push_back(asteroid);
}
