//
// Created by Theodore on 7/16/2025.
//

#include "../include/ACGrid.h"
#include "../include/formulas.h"
#include "SFML/Graphics/RectangleShape.hpp"

void ACGrid::adjustX(const sf::Vector2f x)
{
    rangeX = x;
    setAxisPos();
}

void ACGrid::adjustY(const sf::Vector2f y)
{
    rangeY = y;
    setAxisPos();
}


// Converts a given point on the window's coordinates system to
// a point in the same location on the local coordinate system
sf::Vector2f ACGrid::convertPointToLocal(const sf::Vector2f p) const
{
    const float s_x = formulas::nums::range(rangeY.x, rangeY.y);
    const float s_y = formulas::nums::range(rangeX.x, rangeX.y);
    const sf::Vector2f midp{(rangeX.x+rangeX.y)/2, (rangeY.x+rangeY.y)/2};

    const float x = p.x / winsize::width * s_x;
    const float y = p.y / winsize::height * s_y;

    return sf::Vector2f{x,y} + midp - sf::Vector2f{s_x/2, s_y/2};
}

// Converts a given point on the local coordinate system to a point
// in the same location on the window's coordinate system
sf::Vector2f ACGrid::convertPointToGlobal(const sf::Vector2f p) const
{
    const float s_x = formulas::nums::range(rangeY.x, rangeY.y);
    const float s_y = formulas::nums::range(rangeX.x, rangeX.y);
    const sf::Vector2f midp{(rangeX.x+rangeX.y)/2, (rangeY.x+rangeY.y)/2};

    const float mx = winsize::width / s_x;
    const float my = winsize::height * s_y;
    const sf::Vector2f m = sf::Vector2f{p.x,p.y} - midp + sf::Vector2f{s_x/2, s_y/2};

    return {m.x * mx, m.y * my};
}


void ACGrid::setAxisPos()
{
    const bool renderX = rangeY.x <= 0 && 0 <= rangeY.y;
    const bool renderY = rangeX.x <= 0 && 0 <= rangeX.y;

    // rendering x-axis depends on range of y-axis
    if (renderX)
    {
        const double range = formulas::nums::range(rangeY.x, rangeY.y);
        const float scaleFac = winsize::height / range;
        const float pos = abs(rangeY.x) * scaleFac;
        axisX.setPosition({0, pos - modX});
    }
    else
    {
        if (rangeY.y < 0)
            axisX.setPosition({0, winsize::height - modY});
        else
            axisX.setPosition({0, 0 - modY});
    }


    // rendering y-axis depends on range of x-axis
    if (renderY)
    {
        const double range = formulas::nums::range(rangeX.x, rangeX.y);
        const float scaleFac = winsize::width / range;
        const float pos = abs(rangeX.x) * scaleFac;
        axisY.setPosition({pos - modY, 0});
    }
    else
    {
        if (rangeX.y < 0)
            axisY.setPosition({winsize::width - modX, 0});
        else
            axisY.setPosition({0 - modX, 0});
    }
}
