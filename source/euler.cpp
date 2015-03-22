#include "euler.hpp"

State bs::Euler::integrate(const State &initial, const float dt)
{
    State state = initial;
    state.a = sf::Vector2f(0.0f, 50.0f);
    state.v += state.a * dt;
    state.p += state.v * dt;

    return state;
}
