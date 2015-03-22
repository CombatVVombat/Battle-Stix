#include "physics.hpp"

bs::Physics::Physics()
    : Physics(std::unique_ptr<bs::Integrator>(new Euler()))
{
}

bs::Physics::Physics(std::unique_ptr<bs::Integrator> integrator)
    : _integrator( std::move(integrator))
{
}

void bs::Physics::update(const float dt)
{
    for(StorageListType::iterator it = _physicsBodys.begin(); it != _physicsBodys.end(); ++it)
    {
        it->state = _integrator->integrate(it->state, dt);
    }
}

void bs::Physics::createBody()
{
    _physicsBodys.push_back( bs::RigidBody() );
}

void bs::Physics::forcePosition(const uint32_t index, const sf::Vector2f &position)
{
    _physicsBodys[index].state.p = position;
}
