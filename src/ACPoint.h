//
// Created by Theodore on 7/3/2025.
//

#ifndef ACPOINT_H
#define ACPOINT_H
#include "SFML/Graphics/CircleShape.hpp"


class ACPoint : public sf::Transformable {
private:
    sf::CircleShape dispCircle;
    sf::Vector2f colliderSmallerPoint;
    sf::Vector2f colliderLargerPoint;
    float radius;
public:
    ACPoint(float radius, sf::Vector2f pos);

    bool eventPosWithinRange(sf::Vector2f eventPos) const;
    void moveTo(sf::Vector2f pos);
    void updateCollider();

    sf::CircleShape circle()
    {
        return dispCircle;
    }
};


#endif //ACPOINT_H
