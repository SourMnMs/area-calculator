//
// Created by Theodore on 7/3/2025.
//

#ifndef FORMULAS_H
#define FORMULAS_H
#include <cmath>
#include "SFML/System/Vector2.hpp"

namespace formulas
{
    namespace point
    {
        inline double distance(const sf::Vector2f a, const sf::Vector2f b)
        {
            return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
        }
        inline sf::Vector2f midpoint(const sf::Vector2f a, const sf::Vector2f b)
        {
            return {(a.x+b.x)/2, (a.y+b.y)/2};
        }
    }

    namespace area
    {
        inline double triangle(const double base, const double height)
        {
            return 0.5 * base * height;
        }
        inline double circle(const double radius)
        {
            return M_PI * radius * radius;
        }
        inline double rectangle(const double base, const double height)
        {
            return base * height;
        }
    }

    namespace perimeter
    {
        inline double rectangle(const double base, const double height)
        {
            return 2*base + 2*height;
        }
        inline double circle(const double radius)
        {
            return M_PI * 2 * radius;
        }
    }
}

#endif //FORMULAS_H
