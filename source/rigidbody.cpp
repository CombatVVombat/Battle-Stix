#include "rigidbody.hpp"

void bs::physics::RigidBody::applyForce(const sf::Vector2f &force, const sf::Vector2f &position)
{
    /// Force direction is given in world coordinates
    /// Position is relative to center of mass and given in world coordinates
    _force += force;
    _torque += bs::cross(position, force);
}

void bs::physics::RigidBody::resetForce()
{
    _force = sf::Vector2f(0.0f, 0.0f);
    _torque = 0;
}

void bs::physics::RigidBody::updateAccel(const float dt)
{
    _state._a = _force * _massProperties.getInvMass();
    _state._L += _torque * dt;
    _state._w = _state._L * _massProperties.getInvInertia();
}
