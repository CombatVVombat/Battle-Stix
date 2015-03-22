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
            sf::Vector2f _p;
            sf::Vector2f _v;
            sf::Vector2f _a;
            float _theta;   // angle
            float _w;       // angular velocity
            float _L;       // angular momentum
        };

        /*class Derivative
        {
        public:
            sf::Vector2f _dpdt;
            sf::Vector2f _dvdt;
        };*/
    }
}



#endif // STATE_HPP_INCLUDED
