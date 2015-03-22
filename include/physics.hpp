#ifndef PHYSICS_HPP_INCLUDED
#define PHYSICS_HPP_INCLUDED

#include <memory>
#include <vector>
#include "euler.hpp"
#include "rigidbody.hpp"

typedef std::vector<bs::RigidBody> StorageListType;

namespace bs
{
    class Physics : sf::NonCopyable
    {
    public:
        Physics();  // uses default Euler integrator
        Physics(std::unique_ptr<Integrator> integrator);
        void update(const float dt);
        void createBody();
        void forcePosition(const uint32_t index, const sf::Vector2f &position);

    // public only temporary!
    public:
        std::unique_ptr<Integrator> _integrator;
        StorageListType _physicsBodys;
    };;
}



#endif // PHYSICS_HPP_INCLUDED
