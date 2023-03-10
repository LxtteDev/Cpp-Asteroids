#include "bullet.h"

#ifndef BULLETS_H_
#define BULLETS_H_

class Bullets {
    public:
        Bullets(sf::Texture& texture, Window& window, Asteroids& asteroidHandler);

        void update(float deltaTime);
        void fire(sf::Sprite player);

    private:
        sf::Texture mTexture;
        Window& mWindow;
        std::vector<Bullet> bullets;
        Asteroids& asteroids;
};

#endif