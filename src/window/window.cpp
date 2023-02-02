#include <iostream>
#include "window.h"

Window::Window( int width, int height, std::string name ): RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close, sf::ContextSettings(0, 0, 16)) {}

Window::~Window() {
    // Destory window
}

void Window::setBackgroundColour(sf::Color colour) {
    clear(colour);
}
