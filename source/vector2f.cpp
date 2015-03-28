#include "vector2f.hpp"

bs::Vector2f::Vector2f()
:   sf::Vector2f(0.0f, 0.0f) {}

bs::Vector2f::Vector2f(const float x, const float y)
:   sf::Vector2f(x,y) {}

float bs::Vector2f::length() const
{
    return sqrtf(x*x + y*y);
}

bs::Vector2f::Vector2f(const sf::Vector2f &v)
:   sf::Vector2f(v.x, v.y)  {}

bs::Vector2f bs::Vector2f::normalize()
{
    bs::Vector2f v;
    float len = this->length();
    if(len != 0)
    {
        v.x = this->x /= len;
        v.y = this->y /= len;
    }
    return v;
}

bs::Vector2f bs::Vector2f::unit() const
{
    bs::Vector2f v;
    float len = this->length();
    if(len != 0)
    {
        v.x = this->x / len;
        v.y = this->y / len;
    }
    return v;
}

float bs::cross(const sf::Vector2f &a, const sf::Vector2f &b)
{
    return (a.x * b.y - a.y * b.x);
}

float bs::det(const sf::Vector2f &a, const sf::Vector2f &b)
{
    return (a.x * b.y - a.y * b.x);
}

float bs::dot(const sf::Vector2f &a, const sf::Vector2f &b)
{
    return (a.x * b.x + a.y * b.y);
}

float bs::length(const sf::Vector2f &v)
{
    return sqrtf(v.x*v.x + v.y*v.y);
}

bs::Vector2f bs::leftNormal(const sf::Vector2f &v)
{
    return bs::Vector2f(-v.x, v.y);
}

bs::Vector2f bs::rightNormal(const sf::Vector2f &v)
{
    return bs::Vector2f(v.x, -v.y);
}

float bs::angle(const sf::Vector2f &a, const sf::Vector2f &b)
{
    bs::Vector2f n(a);
    bs::Vector2f m(b);
    n.normalize();
    m.normalize();

    return atan2( det(n,m), dot(n,m) );
}
