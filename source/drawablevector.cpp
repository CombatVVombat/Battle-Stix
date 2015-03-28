#include "drawablevector.hpp"

sf::Vertex bs::DrawableVector::_verts[2] = { sf::Vertex(sf::Vector2f(0.0f, 0.0f), sf::Color::White), sf::Vertex(sf::Vector2f(0.0f, 0.0f), sf::Color::White) };
sf::CircleShape bs::DrawableVector::_pointer = sf::CircleShape(5, 3);

bs::DrawableVector::DrawableVector()
{
    _pointer.setOrigin(5.0f, 5.0f);
}

void bs::DrawableVector::add(const sf::Vector2f &position, const sf::Vector2f &magnitude, sf::Color color)
{
    debugVector v;
    v._color = color;
    v._position = position;
    v._magnitude = magnitude;
    ++_qty;
    _debugVectors.push_back(v);
}

void bs::DrawableVector::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(std::vector<debugVector>::const_iterator iter = _debugVectors.begin(); iter != _debugVectors.end(); ++iter)
    {
        _pointer.setFillColor(iter->_color);
        _pointer.setPosition(iter->_position+iter->_magnitude);
        _pointer.setRotation( 90 - toDeg(bs::angle(iter->_magnitude, sf::Vector2f(1.0f, 0.0f))) );
        _verts[0].color = iter->_color;
        _verts[1].color = iter->_color;
        _verts[0] = iter->_position;
        _verts[1] = iter->_position + iter->_magnitude;
        target.draw(_pointer);
        target.draw(_verts, 2, sf::Lines);
    }
}

uint32_t bs::DrawableVector::getQty() const
{
    return _qty;
}

void bs::DrawableVector::update(const uint32_t index, const sf::Vector2f &position, const sf::Vector2f &magnitude, sf::Color color)
{
    _debugVectors[index]._position = position;
    _debugVectors[index]._magnitude = magnitude;
    _debugVectors[index]._color = color;
}
