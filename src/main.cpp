#include <iostream>
#include "window/window.h"
#include "player/player.h"
#include "bullets/bullets.h"

#define vector2 sf::Vector2u

int main() {
    // Window
	Window window(500, 500, "Asteroids");

    // Asteroids
    sf::Texture asteroidTexture;
    asteroidTexture.loadFromFile("content/img/asteroid-large.png");
    Asteroids asteroidHandler(asteroidTexture, window);

    // Bullets
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("content/img/bullet.png");
    Bullets bulletHandler(bulletTexture, window, asteroidHandler);

    // Player
    sf::Texture playerTexture;
    playerTexture.loadFromFile("content/img/player.png");

    sf::Sprite playerSprite(playerTexture);
    float playerSize = (float)30/512;
    playerSprite.setScale(playerSize, playerSize);

    Player player(playerSprite, window);

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
                    bulletHandler.fire(player.player);
                }
            } else if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
                mouseClicked = 0;

        // Player
        int crash(player.detectCrash(asteroidHandler));
        if (crash)
            break;

        player.handleInput(deltaSeconds);

        // Draw
        window.clear();
        window.draw(player.player);

        // Updates
        asteroidHandler.update(deltaSeconds, player.player.getPosition());
        bulletHandler.update(deltaSeconds);

        // Display
        window.display();
    }

    std::cout << "You died!" << std::endl;
    window.close();
}
