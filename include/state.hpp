#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <SFML/System.hpp>

namespace bs
{
    namespace physics
    {
        class State
        {
        public:
            sf::Vector2f p;
            sf::Vector2f v;
            sf::Vector2f a;
        };
    }
}



#endif // STATE_HPP_INCLUDED
