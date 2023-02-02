#include <iostream>
#include "window.h"

Window::Window( int width, int height, std::string name ): RenderWindow(sf::VideoMode(width, height), name) {}

Window::~Window() {
    // Destory window
}
