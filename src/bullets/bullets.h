#include <SFML/Graphics.hpp>
#include <iostream>
#include "../window/window.h"

class Bullets {
    public:
        Bullets(sf::Sprite sprite, Window& window);

        void update(float deltaTime, sf::Sprite player);
    private:
        Window& mWindow;
};