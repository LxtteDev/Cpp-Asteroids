#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "../window/window.h"

class Player {
    public:
        Player(sf::Sprite player, Window& window);
        ~Player();

        void handleInput(float deltaTime);
        void fire(float deltaTime);

        sf::Sprite player;

    private:
        Window& mWindow;

        float velX = 0;
        float velY = 0;

        float posX = 250;
        float posY = 250;

        sf::Vector2u size;
};