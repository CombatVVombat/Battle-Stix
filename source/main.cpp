#include <random>
#include "clock.hpp"
#include "drawablevector.hpp"
#include "overlay.hpp"
#include "physics.hpp"
#include "timer.hpp"
#include "vector2f.hpp"
#include "window.hpp"

int main()
{
    // Much Temporary Stuff, very much wooooo
    bs::Vector2f windowSize = sf::Vector2f(800.0f, 600.0f);
    uint32_t objectCount = 1;

    bs::Clock mainClock;
    bs::Clock innerClock;
    bs::Timer mainLoopTimer;
    mainLoopTimer.setFrequency(100);

    bs::Overlay overlay;
    overlay.addItem("Run Time: " );
    overlay.addItem("Frame Time: ");
    overlay.addItem("Update Rate: ");

    bs::Physics physics;
    bs::DrawableVector debugVectors;
    debugVectors.add(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), sf::Color::White);
    debugVectors.add(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), sf::Color::White);

    sf::Texture texture;
    if(!texture.loadFromFile("resources/textures/mrplatform.png"))
        throw std::runtime_error(std::string("Failed to load: ") + std::string("mrplatform.png"));
    texture.setSmooth(false);

    std::vector<sf::Sprite> sprites;
    for(unsigned int i = 0; i < objectCount; ++i)
    {
        physics.createBody();
        physics.forcePosition(i, sf::Vector2f(0.0f,0.0f));
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(1.0f, -1.0f);
        sprite.setOrigin(32,32);
        sprites.push_back(sprite);
    }

    bs::Window window(sf::VideoMode(windowSize.x,windowSize.y), "Battle Stix");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowSize.x, -windowSize.y));
    sf::View screen(windowSize/2.0f, windowSize);

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
                physics.applyForce(i, sf::Vector2f(0.0f, -9.8f), sf::Vector2f(16.0f, 0.0f));
                physics.applyForce(i, sf::Vector2f(0.0f, 9.8f), sf::Vector2f(-16.0f, 0.0f));
                sprites[i].setRotation(physics._physicsBodys[i]._state._theta);
                sprites[i].setPosition(physics._physicsBodys[i]._state._p);
            }
            debugVectors.update(0, physics._physicsBodys[0]._state._p + sf::Vector2f(16.0f, 0.0f), sf::Vector2f(0.0f, -98.0f), sf::Color::White);
            debugVectors.update(1, physics._physicsBodys[0]._state._p + sf::Vector2f(-16.0f, 0.0f), sf::Vector2f(0.0f, 98.0f), sf::Color::White);

            overlay.updateItem(0, "Frame Time: " + std::to_string(mainClock.delta.asMicroseconds()) + " us");
            overlay.updateItem(1, "Total Time: " + std::to_string(mainClock.getTimeAlive().asSeconds()) + " seconds");
            overlay.updateItem(2, "Update Rate: " + std::to_string( 1.0f / innerClock.delta.asSeconds() ) + " hz");
        }

        window.handleEvents();
        window.clear(sf::Color::Black);
        window.setView(view);
        for(unsigned int i = 0; i < objectCount; ++i)
            window.draw(sprites[i]);
        window.draw(debugVectors);
        window.setView(screen);
        window.draw(overlay);
        window.display();
    }

    return 0;
}
