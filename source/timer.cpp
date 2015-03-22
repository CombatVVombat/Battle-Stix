#include "timer.hpp"

bs::Timer::Timer()
{
    _duration = sf::milliseconds(1);
}

bool bs::Timer::accumulatorIsFull() const
{
    return( _accumulator >= _duration );
}

void bs::Timer::accumulateTime(const sf::Time &delta)
{
    _accumulator += delta;
}

void bs::Timer::eatTime()
{
    _accumulator -= _duration;
}

void bs::Timer::setDuration(const sf::Time &duration)
{
    _duration = duration;
}

void bs::Timer::setFrequency(uint32_t hz)
{
    _duration = sf::microseconds(1000000/hz);
}




