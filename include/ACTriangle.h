//
// Created by Theodore on 7/13/2025.
//

#ifndef ACTRIANGLE_H
#define ACTRIANGLE_H
#include "SFML/Graphics/ConvexShape.hpp"
#include "ACPoint.h"

class ACTriangle : sf::ConvexShape
{
private:
    std::array<sf::Vector2f, 3> vertices;

    void init();
public:
    explicit ACTriangle(const std::array<ACPoint, 3>& v);
    ACTriangle(const ACPoint& a, const ACPoint& b, const ACPoint& c);
    ACTriangle(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c);

    double getArea() const;
};

#endif //ACTRIANGLE_H
