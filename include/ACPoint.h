//
// Created by Theodore on 7/3/2025.
//

#ifndef ACPOINT_H
#define ACPOINT_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Transformable.hpp"


class ACPoint : public sf::Transformable {
private:
    sf::CircleShape dispCircle;
    sf::FloatRect collider;
    float radius;

public:
    ACPoint(float radius, sf::Vector2f pos);

    void moveTo(sf::Vector2f pos);
    void updateCollider();
    sf::FloatRect getCollider() const
    {
        return collider;
    }
    sf::CircleShape circle() const
    {
        return dispCircle;
    }

};


#endif //ACPOINT_H
