#include "player.h"

// Clamp
float clamp(float value, float lower, float upper) {
    return value < lower ? lower : (value > upper ? upper : value);
}

#define w sf::Keyboard::W
#define s sf::Keyboard::S
#define a sf::Keyboard::A
#define d sf::Keyboard::D
#define keyPressed(key) (sf::Keyboard::isKeyPressed(key))

#define temp(t) (std::cout << "\r" << t << std::flush)

Player::Player() {
    sf::Texture playerTexture;
    playerTexture.loadFromFile("content/img/player.png");

    sf::Sprite sprite(playerTexture);
    float playerSize = (float)30/512;
    sprite.setScale(playerSize, playerSize);

    this->player = sprite;
}

Player::~Player() {
}

void Player::handleInput(float deltaTime) {
    float velocityChange = 2 * deltaTime;
    float threshold = 1e-6f;

    this->velX -= (this->velX / 2.0f) * (deltaTime / 0.21f);
    this->velY -= (this->velY / 2.0f) * (deltaTime / 0.21f);

    if (this->velX < threshold && this->velX > -threshold)
        this->velX = 0.0f;
    if (this->velY < threshold && this->velY > -threshold)
        this->velY = 0.0f;

    this->velX = clamp(this->velX, -10, 10);
    this->velY = clamp(this->velY, -10, 10);
    
    if (keyPressed(w))
        this->velY -= velocityChange;
    if (keyPressed(s))
        this->velY += velocityChange;
    if (keyPressed(a))
        this->velX -= velocityChange;
    if (keyPressed(d))
        this->velX += velocityChange;

    this->posX += this->velX;
    this->posY += this->velY;

    if (this->posX > 500)
        this->posX = 0; 
    else if (this->posX < 0)
        this->posX = 500;

    if (this->posY > 500)
        this->posY = 0; 
    else if (this->posY < 0)
        this->posY = 500;

    this->player.setPosition(sf::Vector2f(this->posX, this->posY));
}