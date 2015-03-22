#ifndef CLOCK_HPP_INCLUDED
#define CLOCK_HPP_INCLUDED

#include <SFML/System.hpp>

namespace bs
{
    class Clock : public sf::Clock
    {
    public:
        sf::Time delta;
        sf::Time getTimeAlive() const;
        sf::Time restart();

    private:
        sf::Time _timeAlive;
    };
}



#endif // CLOCK_HPP_INCLUDED
