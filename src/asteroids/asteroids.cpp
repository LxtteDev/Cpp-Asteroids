#include "asteroids.h"

Asteroids::Asteroids(sf::Texture texture, Window& window): mWindow(window) {
    this->texture = texture;
    
}

Asteroids::~Asteroids() {
}

void Asteroids::update(float deltaTime, sf::Vector2f playerPos) {
    if (this->asteroids.size() < 4)
        createAsteroid(playerPos);
    for (Asteroid& asteroid : this->asteroids) {
        asteroid.draw(deltaTime, this->mWindow); 
    }
}

bool Asteroids::intersect(int index) {
    this->asteroids.erase(this->asteroids.begin() + index);
    return 1;
}

std::vector<Asteroid> &Asteroids::getAsteroids() {
    return this->asteroids;
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
