#include "clock.hpp"

sf::Time bs::Clock::getTimeAlive() const
{
    return _timeAlive;
}

sf::Time bs::Clock::restart()
{
    sf::Time time = sf::Clock::restart();
    _timeAlive += time;
    return time;
}
