#include "../asteroids/asteroids.h"

const float bulletSpeed = 260.0f;

class Bullet {
    public: 
        Bullet(sf::Sprite sprite);

        bool draw(float deltaTime, Window& window, Asteroids& asteroids);

    private:
        sf::Vector2f velocity;
        sf::Sprite mSprite;
};