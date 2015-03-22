#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include <SFML/System.hpp>

namespace bs
{
    class Timer
    {
    public:
        Timer();
        void accumulateTime(const sf::Time &delta);
        bool accumulatorIsFull() const;
        void eatTime();
        void setDuration(const sf::Time &duration);
        void setFrequency(uint32_t frequency);

    private:
        sf::Time _accumulator;
        sf::Time _duration;
    };
}


#endif // TIMER_HPP_INCLUDED
