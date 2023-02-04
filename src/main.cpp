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

    while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e))
			if (e.type == sf::Event::Closed)
				window.close();

        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();

        player.handleInput(deltaSeconds);

        window.clear();
        window.draw(player.player);
        asteroidHandler.update(deltaSeconds, player.player.getPosition());
        window.display();
    }
}
