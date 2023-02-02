#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>

class Player {
    public:
        Player();
        ~Player();

        void handleInput(float deltaTime);

        sf::Sprite player;

    private:
        float velX = 0;
        float velY = 0;
};