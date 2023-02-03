#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../window/window.h"

class Player {
    public:
        Player(sf::Sprite sprite, Window& window);
        ~Player();

        void handleInput(float deltaTime);

        sf::Sprite player;

    private:
        Window& mWindow;

        float velX = 0;
        float velY = 0;

        float posX = 0;
        float posY = 0;

        sf::Vector2u size;
};