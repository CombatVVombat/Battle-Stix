#ifndef INTEGRATOR_HPP_INCLUDED
#define INTEGRATOR_HPP_INCLUDED

#include "state.hpp"

namespace bs
{
    class Integrator
    {
    public:
        virtual bs::physics::State integrate(const bs::physics::State &initial, const float dt) = 0;
    };
}



#endif // INTEGRATOR_HPP_INCLUDED
