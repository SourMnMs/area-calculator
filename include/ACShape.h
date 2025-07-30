//
// Created by Theodore on 7/13/2025.
//

#ifndef ACSHAPE_H
#define ACSHAPE_H
#include "ACTriangle.h"

// This class will be used to handle converting
// complex polygons into triangles for area calculation
// https://en.wikipedia.org/wiki/Polygon_triangulation

class ACShape
{
private:
    std::vector<ACPoint> vertices;
public:
    explicit ACShape(const std::vector<ACPoint>& p) : vertices(p) {}

    ACPoint point(int idx);
    void remove(int idx);

    std::vector<ACTriangle> triangulate();
    double getArea(ACGrid& g);
};

#endif //ACSHAPE_H