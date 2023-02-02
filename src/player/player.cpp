#include "player.h"

#define w sf::Keyboard::W
#define s sf::Keyboard::S
#define a sf::Keyboard::A
#define d sf::Keyboard::D
#define keyPressed(key) (sf::Keyboard::isKeyPressed(key))

#define temp(t) (std::cout << t << std::endl)

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
    float velocityChange = 3 * deltaTime;

    if (keyPressed(w))
        this->velY -= velocityChange;
    if (keyPressed(s))
        this->velY += velocityChange;
    if (keyPressed(a))
        this->velX -= velocityChange;
    if (keyPressed(d))
        this->velX += velocityChange;

    this->velX = std::min( std::max( this->velX, -10 ), 10 );
    this->velY = std::min( std::max( this->velY, -10 ), 10 );

    temp(this->velX);
}