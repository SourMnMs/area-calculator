#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../include/formulas.h"
#include "../include/ACPoint.h"
#include "../include/ACLine.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode({729, 729}), "Area Calculator", sf::Style::Close);
    // win.setPosition({200, 50});
    win.setVerticalSyncEnabled(true);

    /*================== Object Setup ==================*/
    std::vector<ACPoint> points;
    ACPoint *closestToMouse = nullptr;
    ACPoint *draggingPoint = nullptr;
    /*==================================================*/


    while (win.isOpen())
    {

        // checks all the window's events that triggered since the
        // previous iteration of the loop
        while (const std::optional event = win.pollEvent())
        {
            /*================== Event Handling ==================*/
            if (event->is<sf::Event::Closed>())
                win.close();

            // mouse pressed
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                // left click -> check if it was on the closest point to mouse
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    const sf::Vector2f& eventPos = sf::Vector2f(mouseButtonPressed->position);
                    if (closestToMouse && closestToMouse->getCollider().contains(eventPos))
                    {
                        draggingPoint = closestToMouse;
                        std::cout << "mouse click within position" << std::endl;
                    }
                }

                // right click -> make new point, set it as closest point to mouse
                if (mouseButtonPressed->button == sf::Mouse::Button::Right)
                {
                    ACPoint newPoint(5.f, sf::Vector2f(mouseButtonPressed->position));
                    points.push_back(newPoint);
                    closestToMouse = &points[points.size()-1];
                }
            }

            // mouse released
            if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {
                    draggingPoint = nullptr;
                }
            }

            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                if (draggingPoint)
                    draggingPoint->moveTo(sf::Vector2f(mouseMoved->position));
            }

        }


        /*================== Clear-Draw-Display ==================*/
        win.clear(sf::Color::White);

        const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(win));

        const unsigned long long n = points.size();
        for (int i = 0; i < n; i++)
        {
            if (closestToMouse)
            {
                const sf::Vector2f pointPos = points[i].getPosition();
                const double pmDist = formulas::point::distance(pointPos, mousePos);
                const double cmDist = formulas::point::distance(closestToMouse->getPosition(), mousePos);
                if (pmDist < cmDist)
                    closestToMouse = &points[i];
            }
            win.draw(points[i].circle());

            // TODO: MAKE THIS ONE LINE WITH MANY SEGMENTS, NOT MULTIPLE LINES
            if (n > 1)
            {
                const ACPoint& prev = points[((i-1==-1)?n:i) - 1];
                ACLine line(prev, points[i]);
                line.draw(win);
            }
        }



        win.display();
        /*========================================================*/
    }
}
