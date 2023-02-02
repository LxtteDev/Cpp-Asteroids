#include <SFML/Graphics.hpp>
#include <string>

class Window: public sf::RenderWindow {
    public:
        Window(int width, int height, std::string name);
        ~Window();

        void setBackgroundColour(sf::Color colour);
};