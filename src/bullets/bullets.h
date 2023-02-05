#include <vector>
#include "bullet.h"

class Bullets {
    public:
        Bullets(sf::Texture texture, Window& window);

        void update(float deltaTime);
        void fire(sf::Sprite player);

    private:
        sf::Texture mTexture;
        Window& mWindow;
        std::vector<Bullet> bullets;
};