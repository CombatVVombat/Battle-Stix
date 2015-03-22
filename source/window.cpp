#include "window.hpp"

bs::Window::Window(sf::VideoMode mode, const sf::String &title, uint32_t style, const sf::ContextSettings &settings)
: sf::RenderWindow(mode, title, style, settings)
{
}

void bs::Window::handleEvents()
{
    sf::Event event;
    while(this->pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                this->close();
                break;
            default:
                break;
        }
    }
}
