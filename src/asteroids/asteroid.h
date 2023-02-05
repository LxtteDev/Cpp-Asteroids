#include <SFML/Graphics.hpp>
#include <iostream>
#include "../window/window.h"
#include <random>

const float size = 500.0f;
const float asteroidSpeed = 130.0f;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class Asteroid {
    public:
        Asteroid(sf::Sprite sprite, sf::Vector2f playerPos);

        void draw(float deltaTime, Window& window);
        sf::Vector2f velocity;

    private:
        sf::Sprite mSprite;
};