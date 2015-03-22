#ifndef EULER_HPP_INCLUDED
#define EULER_HPP_INCLUDED

#include "integrator.hpp"

typedef bs::physics::State State;

namespace bs
{
    class Euler : public Integrator
    {
    public:
        State integrate(const State &initial, const float dt);
    };
}



#endif // EULER_HPP_INCLUDED
