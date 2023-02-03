#include <SFML/Graphics.hpp>
#include <string>

#ifndef WINDOW_H
#define WINDOW_H

class Window: public sf::RenderWindow {
    public:
        Window(int width, int height, std::string name);
        ~Window();

        sf::Vector2i getMousePosition();
        void setBackgroundColour(sf::Color colour);
};

#endif