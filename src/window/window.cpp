#include <iostream>
#include "window.h"

Window::Window( int width, int height, std::string name ): sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close, sf::ContextSettings(0, 0, 16)) {}

Window::~Window() {
    // Destory window
}

sf::Vector2i Window::getMousePosition() {
    return sf::Mouse::getPosition(*this);
}

void Window::setBackgroundColour(sf::Color colour) {
    clear(colour);
}
