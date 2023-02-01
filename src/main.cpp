#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main(int, char**) {
    std::cout << "Hello, world!\n";

	RenderWindow window(VideoMode(100, 100), "Test");
    window.display();
}
