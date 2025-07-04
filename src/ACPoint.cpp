//
// Created by Theodore on 7/3/2025.
//

#include "ACPoint.h"

ACPoint::ACPoint(const float radius, const sf::Vector2f pos)
{
    this->radius = radius;
    setPosition(pos);
    colliderSmallerPoint = {pos.x-radius, pos.y-radius};
    colliderLargerPoint = {pos.x+radius, pos.y+radius};

    dispCircle = sf::CircleShape(radius);
    dispCircle.setFillColor(sf::Color(100, 250, 50));
    dispCircle.setPosition(colliderSmallerPoint);
}

void ACPoint::updateCollider()
{
    const sf::Vector2f pos = getPosition();
    colliderSmallerPoint = {pos.x-radius, pos.y-radius};
    colliderLargerPoint = {pos.x+radius, pos.y+radius};
}

bool ACPoint::eventPosWithinRange(const sf::Vector2f eventPos) const
{
    const bool less = colliderSmallerPoint.x < eventPos.x && colliderSmallerPoint.y < eventPos.y;
    const bool greater = eventPos.x < colliderLargerPoint.x && eventPos.y < colliderLargerPoint.y;
    return less && greater;
}

void ACPoint::moveTo(const sf::Vector2f pos)
{

    setPosition(pos);
    updateCollider();
    dispCircle.setPosition(colliderSmallerPoint);
}
