#include "physics.hpp"

bs::Physics::Physics()
    : Physics(std::unique_ptr<bs::Integrator>(new Euler()))
{
}

bs::Physics::Physics(std::unique_ptr<bs::Integrator> integrator)
    : _integrator( std::move(integrator))
{
}

void bs::Physics::applyForce(const uint32_t index, const sf::Vector2f &force, const sf::Vector2f &position)
{
    _physicsBodys[index].applyForce(force, position);
}

void bs::Physics::update(const float dt)
{
    for(StorageListType::iterator it = _physicsBodys.begin(); it != _physicsBodys.end(); ++it)
    {
        it->updateAccel(dt);
        it->_state = _integrator->integrate(it->_state, dt);
        it->resetForce();
    }
}

void bs::Physics::createBody()
{
    _physicsBodys.push_back( bs::physics::RigidBody() );
}

void bs::Physics::forcePosition(const uint32_t index, const sf::Vector2f &position)
{
    _physicsBodys[index]._state._p = position;
}
