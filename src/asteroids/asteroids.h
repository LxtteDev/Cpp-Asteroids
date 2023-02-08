#include <vector>
#include "asteroid.h"

#ifndef ASTEROIDS_H_
#define ASTEROIDS_H_

class Asteroids {
    public:
        Asteroids(sf::Texture texture, Window& window);
        ~Asteroids();

        void update(float deltaTime, sf::Vector2f playerPos);
        bool intersect(int index);
        std::vector<Asteroid>& getAsteroids();

    private:
        void createAsteroid(sf::Vector2f playerPos);

    private:
        Window& mWindow;
        sf::Texture texture;
        std::vector<Asteroid> asteroids;
};

#endif
