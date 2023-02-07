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
    Asteroid asteroid = this->asteroids[index];
    this->asteroids.erase(this->asteroids.begin() + index);

    if (asteroid.mType) {
        sf::Vector2f position = asteroid.mSprite.getPosition();
        
        sf::Sprite sprite(this->texture);

        float asteroidSize = (float)30/512;
        sprite.setScale(asteroidSize, asteroidSize);
        
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);

        Asteroid asteroid(sprite, position, sf::Vector2f(0, 0), 0);
        this->asteroids.push_back(asteroid);
    }

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
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 500);

    int x = dis(gen);
    int y = dis(gen);

    if (x >= y)
        y = std::floor(y / 500 + 0.5);
    else if (y >= x)
        x = std::floor(x / 500 + 0.5);

    sf::Vector2f position(x, y);

    sf::Vector2f velocity = playerPos - position;
    velocity = sf::Vector2f(velocity.x / 500, velocity.y / 500);
    velocity = sf::Vector2f(velocity.x * asteroidSpeed, velocity.y * asteroidSpeed);

    Asteroid asteroid(sprite, position, velocity, 1);
    this->asteroids.push_back(asteroid);
}
