#include <SFML/Graphics.hpp>
#include <iostream>
#include "../window/window.h"

const float bulletSpeed = 260.0f;

class Bullet {
    public: 
        Bullet(sf::Sprite sprite);

        bool draw(float deltaTime, Window& window);

    private:
        sf::Vector2f velocity;
        sf::Sprite mSprite;
};