//
// Created by Theodore on 7/5/2025.
//

#include "../include/ACLine.h"

ACLine::ACLine(const ACPoint& a, const ACPoint& b)
{
    line[0] = sf::Vertex{a.getPosition(), sf::Color::Red};
    line[1] = sf::Vertex{b.getPosition(), sf::Color::Red};
}


ACLine::ACLine(const sf::Vector2f a, const sf::Vector2f b)
{
    line[0] = sf::Vertex{a};
    line[1] = sf::Vertex{b};
}


void ACLine::draw(sf::RenderWindow& window)
{
    window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
}
