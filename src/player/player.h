#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "../asteroids/asteroids.h"

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
    public:
        Player(sf::Sprite player, Window& window);
        ~Player();

        void handleInput(float deltaTime);
        void fire(float deltaTime);
        int detectCrash(Asteroids& asteroids);

        sf::Sprite player;

    private:
        Window& mWindow;

        float velX = 0;
        float velY = 0;

        float posX = 250;
        float posY = 250;

        sf::Vector2u mSize;
};

#endif
