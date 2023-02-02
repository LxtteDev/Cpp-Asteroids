#include <iostream>
#include "window/window.h"
#include "player/player.h"

#define vector2 sf::Vector2u

int main(int, char**) {
    std::cout << "Starting Astroids!" << std::endl;

	Window window(500, 500, "Asteroids");
    Player player;

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
        window.display();
    }
}
