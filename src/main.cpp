#include <iostream>
#include "window/window.h"
#include "player/player.h"
#include "asteroids/asteroids.h"

#define vector2 sf::Vector2u

int main(int, char**) {
    std::cout << "Starting Astroids!" << std::endl;

	Window window(500, 500, "Asteroids");

    
    sf::Texture asteroidTexture;
    asteroidTexture.loadFromFile("content/img/asteroid-large.png");
    Asteroids asteroidHandler(asteroidTexture, window);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("content/img/player.png");

    sf::Sprite sprite(playerTexture);
    float playerSize = (float)30/512;
    sprite.setScale(playerSize, playerSize);

    Player player(sprite, window);

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
                    player.fire(deltaSeconds);
                }
            } else if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
                mouseClicked = 0;

        // Player
        player.handleInput(deltaSeconds);

        // Draw
        window.clear();
        window.draw(player.player);
        asteroidHandler.update(deltaSeconds, player.player.getPosition());

        // Display
        window.display();
    }
}
