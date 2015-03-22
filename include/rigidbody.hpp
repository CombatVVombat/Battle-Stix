#ifndef RIGIDBODY_HPP_INCLUDED
#define RIGIDBODY_HPP_INCLUDED

#include "massproperties.hpp"
#include "state.hpp"

namespace bs
{
    namespace physics
    {
        class RigidBody
        {
        public:
            bs::physics::State _state;
            bs::physics::MassProperties _massProperties;

            void applyForce(const sf::Vector2f &force, const sf::Vector2f &position);
            void updateAccel(const float dt);
            void resetForce();

        private:
            sf::Vector2f _force;
            float _torque;
        };
    }
}


#endif // RIGIDBODY_HPP_INCLUDED
