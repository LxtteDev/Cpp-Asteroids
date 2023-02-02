#include <iostream>
#include "window/window.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";

	Window window(600, 250, "Window test");

    while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
        }

        window.display();
    }
}
