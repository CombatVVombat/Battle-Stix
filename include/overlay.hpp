#ifndef OVERLAY_HPP_INCLUDED
#define OVERLAY_HPP_INCLUDED

#include <SFML/Graphics.hpp>

typedef std::vector<sf::Text> textBucket;

namespace bs
{
   class Overlay : public sf::Drawable
    {
    public:
        Overlay();
        void addItem(const std::string &description);
        void updateItem(const uint32_t index, const std::string &s);

    private:
        sf::Font _font;
        textBucket _texts;
        uint32_t _qty;
        static const uint32_t _topOffset = 0;
        static const uint32_t _leftOffset = 0;
        static const uint32_t _rowSpacing = 20;
        static const uint32_t _columnSpacing = 200;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}




#endif // OVERLAY_HPP_INCLUDED
