#ifndef VECTOR2F_HPP_INCLUDED
#define VECTOR2F_HPP_INCLUDED

#include <cmath>
#include <SFML/system.hpp>

namespace bs
{
    class Vector2f : public sf::Vector2f
    {
    public:
        Vector2f();
        Vector2f(const float x, const float y);
        Vector2f(const sf::Vector2f &v);

        float length() const;
        bs::Vector2f normalize();
        bs::Vector2f unit() const;
        bs::Vector2f& operator*=(const float &s) { x *= s;  y *= s; return *this; }
        bs::Vector2f& operator/=(const float &s) { x /= s; y /= s;  return *this; }
    };

    float angle(const sf::Vector2f &a, const sf::Vector2f &b);
    float cross(const sf::Vector2f &a, const sf::Vector2f &b);
    float det(const sf::Vector2f &a, const sf::Vector2f &b);
    float dot(const sf::Vector2f &a, const sf::Vector2f &b);
    float length(const sf::Vector2f &v);
    bs::Vector2f leftNormal(const sf::Vector2f &v);
    bs::Vector2f rightNormal(const sf::Vector2f &v);
}




#endif // VECTOR2F_HPP_INCLUDED
