#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../window/window.h"
#include "asteroid.h"

class Asteroids {
    public:
        Asteroids(sf::Texture texture, Window& window);
        ~Asteroids();

        void update(float deltaTime, sf::Vector2f playerPos);

    private:
        void createAsteroid(sf::Vector2f playerPos);

    private:
        Window& mWindow;
        sf::Texture texture;
        std::vector<Asteroid> asteroids;
};
