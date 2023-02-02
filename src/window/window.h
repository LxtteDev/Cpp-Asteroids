#include <SFML/Graphics.hpp>
#include <string>

class Window: public sf::RenderWindow {
    public:
        Window(int width, int height, std::string name);
        ~Window();

    private:
        // sf::RenderWindow window;
};