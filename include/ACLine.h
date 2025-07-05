//
// Created by Theodore on 7/5/2025.
//

#ifndef ACLINE_H
#define ACLINE_H
#include "ACPoint.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Transformable.hpp"

// TODO: MAKE THIS ONE LINE WITH MANY SEGMENTS, NOT MULTIPLE LINES

class ACLine : public sf::Transformable
{
private:
    std::array<sf::Vertex, 2> line;
public:
    ACLine(const ACPoint& a, const ACPoint& b);
    ACLine(sf::Vector2f a, sf::Vector2f b);

    void draw(sf::RenderWindow& window);
};

#endif //ACLINE_H
