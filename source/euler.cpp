#include "euler.hpp"

State bs::Euler::integrate(const State &initial, const float dt)
{
    State state = initial;
    state._v += state._a * dt;
    state._p += state._v * dt;

    state._theta += state._w * dt;

    return state;
}
