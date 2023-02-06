#include "bullet.h"

Bullet::Bullet(sf::Sprite sprite): mSprite(sprite) {
    float angle = sprite.getRotation();

    this->velocity.x = std::cos(angle * 3.14159265 / 180) * bulletSpeed;
    this->velocity.y = std::sin(angle * 3.14159265 / 180) * bulletSpeed;
}

bool Bullet::draw(float deltaTime, Window &window, Asteroids& asteroids) {    
    this->mSprite.move(this->velocity * deltaTime);

    sf::Vector2f position(this->mSprite.getPosition());
    if (position.x < 0 || position.y < 0 || position.x > 500 || position.y > 500)
        return 1;

    sf::FloatRect bounds(this->mSprite.getGlobalBounds());
    std::vector<Asteroid>& asteroidsElements(asteroids.getAsteroids());
    for (int i = 0; i < asteroidsElements.size(); i++) {
        Asteroid& asteroid = asteroidsElements[i];
        if (asteroid.bounds().intersects(bounds))
            if (asteroids.intersect(i))
                return 1;
    }

    window.draw(this->mSprite);
    return 0;
}
