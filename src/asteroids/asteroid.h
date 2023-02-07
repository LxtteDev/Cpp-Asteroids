#include <SFML/Graphics.hpp>
#include <iostream>
#include "../window/window.h"
#include <random>

const float size = 500.0f;
const float asteroidSpeed = 130.0f;

class Asteroid {
    public:
        Asteroid(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool type);

        void draw(float deltaTime, Window& window);

        sf::FloatRect bounds();
        sf::Sprite mSprite;
        bool mType;

    private:
        sf::Vector2f mVelocity;
};