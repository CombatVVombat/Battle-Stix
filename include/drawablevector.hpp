#ifndef DRAWABLEVECTOR_HPP_INCLUDED
#define DRAWABLEVECTOR_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "conversions.hpp"
#include "vector2f.hpp"

struct debugVector
{
    sf::Color _color;
    sf::Vector2f _position;
    sf::Vector2f _magnitude;
};

namespace bs
{
    class DrawableVector : public sf::Drawable
    {
    public:
        DrawableVector();
        void add(const sf::Vector2f &position, const sf::Vector2f &magnitude, sf::Color color);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        uint32_t getQty() const;
        void update(const uint32_t index, const sf::Vector2f &position, const sf::Vector2f &magnitude, sf::Color color);
    private:
        std::vector<debugVector> _debugVectors;
        uint32_t _qty;
        static sf::CircleShape _pointer;
        static sf::Vertex _verts[2];

    };
}



#endif // DRAWABLEVECTOR_HPP_INCLUDED
