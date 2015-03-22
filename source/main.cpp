#include <random>
#include "clock.hpp"
#include "overlay.hpp"
#include "physics.hpp"
#include "timer.hpp"
#include "window.hpp"

int main()
{
    uint32_t objectCount = 100;  // very temporary
    std::default_random_engine randomEngine;
    std::normal_distribution<float> distribution(300.0f, 300.0f);
    std::normal_distribution<float> dist(-10.0f, 10.0f);

    bs::Clock mainClock;
    bs::Clock innerClock;
    bs::Timer mainLoopTimer;
    mainLoopTimer.setFrequency(100);

    bs::Overlay overlay;
    overlay.addItem("Run Time: " );
    overlay.addItem("Frame Time: ");
    overlay.addItem("Update Rate: ");

    bs::Physics physics;

    sf::Texture texture;
    if(!texture.loadFromFile("resources/textures/mrplatform.png"))
        throw std::runtime_error(std::string("Failed to load: ") + std::string("mrplatform.png"));
    texture.setSmooth(false);

    std::vector<sf::Sprite> sprites;
    for(unsigned int i = 0; i < objectCount; ++i)
    {
        physics.createBody();
        physics.forcePosition(i, sf::Vector2f(distribution(randomEngine), distribution(randomEngine)) );
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setOrigin(32,32);
        sprites.push_back(sprite);
    }

    bs::Window window(sf::VideoMode(800,600), "Battle Stix");

    while(window.isOpen())
    {
        mainClock.delta = mainClock.restart();
        mainLoopTimer.accumulateTime(mainClock.delta);

        while(mainLoopTimer.accumulatorIsFull())
        {
            innerClock.delta = innerClock.restart();
            mainLoopTimer.eatTime();

            physics.update(innerClock.delta.asSeconds());

            for(unsigned int i = 0; i < objectCount; ++i)
            {
                physics.applyForce(i, sf::Vector2f(dist(randomEngine), 0), sf::Vector2f(0, dist(randomEngine)));
                physics.applyForce(i, sf::Vector2f(-dist(randomEngine), 0), sf::Vector2f(0, -dist(randomEngine)));

                sprites[i].setRotation(physics._physicsBodys[i]._state._theta);
                sprites[i].setPosition(physics._physicsBodys[i]._state._p);
            }
            overlay.updateItem(0, "Frame Time: " + std::to_string(mainClock.delta.asMicroseconds()) + " us");
            overlay.updateItem(1, "Total Time: " + std::to_string(mainClock.getTimeAlive().asSeconds()) + " seconds");
            overlay.updateItem(2, "Update Rate: " + std::to_string( 1.0f / innerClock.delta.asSeconds() ) + " hz");
        }

        window.handleEvents();
        window.clear(sf::Color::Black);
        for(unsigned int i = 0; i < objectCount; ++i)
            window.draw(sprites[i]);
        window.draw(overlay);
        window.display();
    }

    return 0;
}
