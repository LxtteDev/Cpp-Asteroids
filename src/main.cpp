#include <iostream>
#include "window/window.h"
#include "player/player.h"
#include "asteroids/asteroids.h"
#include "bullets/bullets.h"

#define vector2 sf::Vector2u

int main() {
    std::cout << "Starting Astroids!" << std::endl;

    // Window
	Window window(500, 500, "Asteroids");

    // Asteroids
    sf::Texture asteroidTexture;
    asteroidTexture.loadFromFile("content/img/asteroid-large.png");
    Asteroids asteroidHandler(asteroidTexture, window);

    // Player
    sf::Texture playerTexture;
    playerTexture.loadFromFile("content/img/player.png");

    sf::Sprite playerSprite(playerTexture);
    float playerSize = (float)30/512;
    playerSprite.setScale(playerSize, playerSize);

    Player player(playerSprite, window);

    // Bullets
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("content/img/bullet.png");

    sf::Sprite bulletSprite(bulletTexture);
    float bulletSize = (float)30/512;
    bulletSprite.setScale(bulletSize, bulletSize);

    Bullets bulletHandler(bulletSprite, window);

    sf::Clock clock;
    bool mouseClicked = 0;

    while (window.isOpen()) {
        // Delta Time
        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();

        // Events
		sf::Event e;
		while (window.pollEvent(e))
			if (e.type == sf::Event::Closed)
				window.close();
            else if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
                if (!mouseClicked) {
                    mouseClicked = 1;
                    // player.fire(deltaSeconds);
                }
            } else if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
                mouseClicked = 0;

        // Player
        player.handleInput(deltaSeconds);

        // Draw
        window.clear();
        window.draw(player.player);

        // Updates
        asteroidHandler.update(deltaSeconds, player.player.getPosition());
        bulletHandler.update(deltaSeconds, player.player);

        // Display
        window.display();
    }
}
