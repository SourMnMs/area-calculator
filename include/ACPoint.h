//
// Created by Theodore on 7/3/2025.
//

#ifndef ACPOINT_H
#define ACPOINT_H
#include "ACGrid.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Transformable.hpp"

// Handles the draggable points

class ACPoint : public sf::Transformable {
private:
    sf::CircleShape dispCircle;
    sf::FloatRect collider;
    float radius;
    ACGrid g;
    sf::Vector2f localPos;
public:
    ACPoint(float radius, sf::Vector2f pos, const ACGrid& g);

    void moveTo(sf::Vector2f pos);
    void updateCollider();

    sf::Vector2f getLocalPosition() const
    {
        return localPos;
    }
    sf::FloatRect getCollider() const
    {
        return collider;
    }
    sf::CircleShape circle() const
    {
        return dispCircle;
    }
};

struct ACPListNode
{
    ACPListNode* prev;
    ACPListNode* next;
    const ACPoint* point;

    ACPListNode(const ACPoint& p)
    {
        prev = this;
        next = this;
        point = &p;
    }
    void addNode(ACPListNode& n)
    {
        n.prev = this;
        n.next = next;
        next->prev = &n;
        next = &n;
    }
};


#endif //ACPOINT_H
