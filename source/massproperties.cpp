#include "massproperties.hpp"

bs::physics::MassProperties::MassProperties()
{
    _invMass = 1.0f;
    _invInertia = 1.0f;
}

float bs::physics::MassProperties::getInvInertia() const
{
    return _invInertia;
}

float bs::physics::MassProperties::getInvMass() const
{
    return _invMass;
}
