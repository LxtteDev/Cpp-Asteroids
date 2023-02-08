#include "player.h"

const float threshold = 1e-6f;
const float maxSpeed = 0.1f;

// Clamp
float clamp(float value, float lower, float upper) {
    return value < lower ? lower : (value > upper ? upper : value);
}

#define w sf::Keyboard::W
#define s sf::Keyboard::S
#define a sf::Keyboard::A
#define d sf::Keyboard::D
#define keyPressed(key) (sf::Keyboard::isKeyPressed(key))

Player::Player(sf::Sprite player, Window& window): mWindow(window) {

    sf::FloatRect bounds = player.getLocalBounds();
    player.setOrigin(bounds.width / 3, bounds.height / 2);

    this->player = player;
}

Player::~Player() {
}

void Player::handleInput(float deltaTime) {
    // Position
    float velocityChange = 1.2f * deltaTime;

    this->velX -= (this->velX / 2.0f) * (deltaTime / 0.21f);
    this->velY -= (this->velY / 2.0f) * (deltaTime / 0.21f);

    if (this->velX < threshold && this->velX > -threshold)
        this->velX = 0.0f;
    if (this->velY < threshold && this->velY > -threshold)
        this->velY = 0.0f;
    
    if (keyPressed(w))
        this->velY -= velocityChange;
    if (keyPressed(s))
        this->velY += velocityChange;
    if (keyPressed(a))
        this->velX -= velocityChange;
    if (keyPressed(d))
        this->velX += velocityChange;

    this->velX = clamp(this->velX, -maxSpeed, maxSpeed);
    this->velY = clamp(this->velY, -maxSpeed, maxSpeed);

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

    // this->player.setPosition(sf::Vector2f(this->posX - this->size.x / 2, this->posY - this->size.y / 2));
    this->player.setPosition(sf::Vector2f(this->posX, this->posY));

    // Rotation
    sf::Vector2i mousePos = this->mWindow.getMousePosition();
    float rotation = atan2(mousePos.y - this->posY, mousePos.x - this->posX) * 180 / 3.1415;

    this->player.setRotation(rotation);
}

int Player::detectCrash(Asteroids& asteroids) {
    sf::FloatRect bounds(this->player.getGlobalBounds());
    std::vector<Asteroid>& asteroidsElements(asteroids.getAsteroids());

    for (int i = 0; i < asteroidsElements.size(); i++) {
        Asteroid& asteroid = asteroidsElements[i];
        if (asteroid.bounds().intersects(bounds))
            return 1;
    }

    return 0;
}