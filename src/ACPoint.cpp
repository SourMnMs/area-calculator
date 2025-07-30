//
// Created by Theodore on 7/3/2025.
//

#include "../include/ACPoint.h"


ACPoint::ACPoint(const float radius, const sf::Vector2f pos, const ACGrid& g): radius(radius), g(g)
{
    dispCircle = sf::CircleShape(radius);
    dispCircle.setFillColor(sf::Color(25, 113, 255));

    moveTo(pos);
}


void ACPoint::updateCollider()
{
    const sf::Vector2f pos = getPosition();
    const float altRad = 3*radius;
    collider = sf::FloatRect({pos.x-altRad/2, pos.y-altRad/2}, {altRad, 3*altRad});
}

void ACPoint::moveTo(const sf::Vector2f pos)
{
    setPosition(pos);
    localPos = g.convertPointToLocal(pos);
    updateCollider();
    dispCircle.setPosition({pos.x-radius, pos.y-radius});
}
