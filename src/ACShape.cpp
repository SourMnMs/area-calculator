//
// Created by Theodore on 7/13/2025.
//

#include "../include/ACShape.h"
#include <iostream>
#include "../include/circvec.h"
#include "../include/ACPoint.h"
#include "../include/formulas.h"
#include "../include/LinkedList.h"

ACPoint ACShape::point(int idx)
{
    idx = idx<0 ? vertices.size()-abs(idx) : idx;
    return vertices[idx % vertices.size()];
}
void ACShape::remove(int idx)
{
    idx = idx<0 ? vertices.size()-abs(idx) : idx;
    vertices.erase(vertices.begin() + (idx % vertices.size())-1);
}


// Uses a circular version of a vector (circvec) to store temporary points.
// Goes through each point to determine if it both (has a concave angle
// when compared to its neighbors) and (the triangle formed by it and
// its neighbors has no points inside it). If so, the triangle is
// added to the result vector<ACTriangle> and the point is removed
// from the circvec.
std::vector<ACTriangle> ACShape::triangulate()
{
    std::cout << "Triangulating" << std::endl;

    circvec<ACPoint> temp{vertices};
    std::vector<ACTriangle> t = {};

    // While the shape isn't a triangle
    int idx = 0;
    while (temp.size() > 3)
    {
        std::cout << std::endl;
        std::cout << "point " << idx+1 << "/" << temp.size() << std::endl;

        // Get the current point and its neighbors
        const sf::Vector2f a = temp.get(idx-1).getPosition();
        const sf::Vector2f b = temp.get(idx).getPosition();
        const sf::Vector2f c = temp.get(idx+1).getPosition();

        // If the interior angle formed is concave
        if (formulas::point::isConcaveAngle(a, b, c))
        {
            std::string ps = std::to_string(temp.circIdx(idx-1)+1) + " " + std::to_string(temp.circIdx(idx)+1) + " " + std::to_string(temp.circIdx(idx+1)+1);
            std::cout << "Found concave angle: " << ps << std::endl;

            // Make a new triangle out of the points
            ACTriangle nt{a, b, c};

            bool good = true;
            const int n = temp.size();
            for (int i = 0; i < n; i++)
            {
                if (!nt.triangleHasPoint(temp.get(i)))
                {
                    std::cout << "Checking point " << i+1 << std::endl;
                    if (nt.pointInsideTriangle(temp.get(i)))
                    {
                        std::cout << "Found point " << i+1 << " inside triangle" << std::endl;
                        good = false;
                        break;
                    }
                }
            }

            // If the triangle doesn't overlap any points, add
            // it to the result vector and remove the point from
            // the point vector
            if (good)
            {
                std::cout << "Found good triangle" << std::endl;

                t.push_back(nt);
                temp.erase(idx);
                idx--;
            }
        }
        idx++;
    }
    t.emplace_back(temp.get(0), temp.get(-1), temp.get(1));

    return t;
}


double ACShape::getArea(ACGrid& g)
{
    std::cout << "Getting area" << std::endl;

    std::vector<ACTriangle> tv = triangulate();

    std::cout << "Made " << tv.size() << " triangles" << std::endl;

    double result = 0;

    const int n = tv.size();
    for (int i = 0; i < n; i++)
        result += tv[i].getLocalArea(g);

    return result;
}
