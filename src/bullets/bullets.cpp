#include "bullets.h"

Bullets::Bullets(sf::Sprite sprite, Window& window): mWindow(window) {
    std::cout << "Bullet handler" << std::endl;
}

void Bullets::update(float deltaTime, sf::Sprite player) {
    // std::cout << "Update" << std::endl;
}
 