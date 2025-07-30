//
// Created by Theodore on 7/13/2025.
//

#include "../include/ACTriangle.h"

#include <iostream>

#include "../include/formulas.h"

// ACTriangle::ACTriangle(const std::array<ACPoint, 3>& v) : vertices()
// {
//     init();
// }
ACTriangle::ACTriangle(const ACPoint& a, const ACPoint& b, const ACPoint& c): vertices()
{
    vertices = {a.getPosition(), b.getPosition(), c.getPosition()};
    init();
}
ACTriangle::ACTriangle(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c): vertices()
{
    vertices = {a, b, c};
    init();
}

void ACTriangle::init()
{
    setPointCount(3);
    setPoint(0, vertices[0]);
    setPoint(1, vertices[1]);
    setPoint(2, vertices[2]);
}

/* OLD CODE: Calculates area by getting the height as the distance
 * between point C and (the point of intersection between line(A,B)
 * and (the line perpendicular to line(A,B) that intersects point C))
 * where A, B, C are the three vertices
 *
// double ACTriangle::getArea()
// {
//     double height;
//     if (A.y == B.y)
//     {
//         if (C.y > A.y)
//             height = C.y - A.y;
//         else
//             height = C.y;
//     }
//     else
//     {
//         const float a = (B.y - A.y)/(B.x - A.x);
//         const float c = a * -A.x + A.y;
//         const float b = -1/a;
//         const float d = b * -C.x + C.y;
//
//         const sf::Vector2f I = {(d-c)/(a-b), a*((d-c)/(a-b))+c};
//         height = formulas::point::distance(I, C);
//     }
//
//     const double base = formulas::point::distance(A, B);
//
//     return formulas::area::triangle(base, height);
// }
*/

double ACTriangle::getArea()
{
    const sf::Vector2f& A = vertices[0];
    const sf::Vector2f& B = vertices[1];
    const sf::Vector2f& C = vertices[2];

    return formulas::area::triangle(A, B, C);
}

double ACTriangle::getLocalArea(const ACGrid& g)
{
    const sf::Vector2f A = g.convertPointToLocal(vertices[0]);
    const sf::Vector2f B = g.convertPointToLocal(vertices[1]);
    const sf::Vector2f C = g.convertPointToLocal(vertices[2]);
    return formulas::area::triangle(A, B, C);
}


// If a point is INSIDE a triangle
bool ACTriangle::pointInsideTriangle(const ACPoint& p)
{
    const sf::Vector2f lp = p.getPosition();
    ACTriangle a{vertices[0], vertices[1], lp};
    ACTriangle b{lp, vertices[1], vertices[2]};
    ACTriangle c{vertices[2], lp, vertices[0]};

    std::cout << "pos: " << lp.x << ", " << lp.y << std::endl;
    std::cout << "Sum of three: " << (a.getArea() + b.getArea() + c.getArea()) << std::endl;
    std::cout << "Area: " << getArea() << std::endl;

    bool test = (a.getArea() + b.getArea() + c.getArea()) == getArea();

    if (test)
        std::cout << "found point inside triangle at " << lp.x << ", " << lp.y << std::endl;

    return test;
}

// If a point is one of the triangle's vertices
bool ACTriangle::triangleHasPoint(const ACPoint& p)
{
    const sf::Vector2f lp = p.getPosition();
    return lp == vertices[0] || lp == vertices[1] || lp == vertices[2];
}
