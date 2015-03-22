#ifndef MASSPROPERTIES_HPP_INCLUDED
#define MASSPROPERTIES_HPP_INCLUDED

namespace bs
{
    namespace physics
    {
        class MassProperties
        {
        public:
            MassProperties();
            float getInvInertia() const;
            float getInvMass() const;
        private:
            float _invMass;
            float _invInertia;
        };
    }
}



#endif // MASSPROPERTIES_HPP_INCLUDED
