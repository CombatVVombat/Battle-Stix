#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <SFML/Graphics.hpp>

namespace bs
{
    class Window : public sf::RenderWindow
    {
    public:
        Window(sf::VideoMode mode, const sf::String &title, uint32_t style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
        void handleEvents();
    };
}

#endif // RENDERWINDOW_HPP_INCLUDED
