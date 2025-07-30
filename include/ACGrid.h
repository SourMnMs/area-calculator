//
// Created by Theodore on 7/16/2025.
//

#ifndef ACGRID_H
#define ACGRID_H

#include "winsize.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class ACGrid
{
private:
    sf::RectangleShape axisX{{winsize::width, 2}};
    sf::RectangleShape axisY{{2, winsize::height}};
    float modX = axisX.getSize().y/2;
    float modY = axisY.getSize().x/2;

    sf::Vector2f rangeX;
    sf::Vector2f rangeY;

    void setAxisPos();
public:
    ACGrid(const sf::Vector2f x, const sf::Vector2f y) : rangeX(x), rangeY(y)
    {
        setAxisPos();
        axisX.setFillColor(sf::Color::Black);
        axisY.setFillColor(sf::Color::Black);
    }

    void adjustX(sf::Vector2f x);
    void adjustY(sf::Vector2f y);

    sf::Vector2f getRangeX() const
    {
        return rangeX;
    }
    sf::Vector2f getRangeY() const
    {
        return rangeY;
    }

    sf::Vector2f convertPointToLocal(sf::Vector2f p) const;
    sf::Vector2f convertPointToGlobal(sf::Vector2f p) const;

    void draw(sf::RenderWindow& win) const
    {
        win.draw(axisX);
        win.draw(axisY);
    }
};

#endif //ACGRID_H
