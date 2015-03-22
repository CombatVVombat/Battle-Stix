#include "overlay.hpp"

bs::Overlay::Overlay()
{
    _qty = 0;
    if(!_font.loadFromFile("resources/fonts/DejaVuSans.ttf"))
        throw std::runtime_error("Font failed to load.");
}

void bs::Overlay::addItem(const std::string &description)
{
    sf::Text text;
    text.setFont(_font);
    text.setColor(sf::Color::White);
    text.setString(description);
    text.setCharacterSize(15);
    text.setPosition(_leftOffset, _topOffset+(_qty*_rowSpacing));
    _texts.push_back(text);
    ++_qty;
}

void bs::Overlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(textBucket::const_iterator iter = _texts.begin(); iter != _texts.end(); ++iter)
    {
        target.draw(*iter);
    }
}

void bs::Overlay::updateItem(const uint32_t index, const std::string &s)
{
    _texts[index].setString(s);
}
