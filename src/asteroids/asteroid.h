#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "../window/window.h"

#ifndef ASTEROID_H_
#define ASTEROID_H_

const float size = 500.0f;
const float asteroidSpeed = 130.0f;

class Asteroid {
    public:
        Asteroid(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool type);

        void draw(float deltaTime, Window& window);

        sf::FloatRect bounds();
        sf::Sprite mSprite;
        sf::Vector2f mVelocity;
        bool mType;

    private:
};

#endif