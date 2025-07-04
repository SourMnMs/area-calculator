#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ACPoint.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode({729, 729}), "Area Calculator", sf::Style::Close);
    // win.setPosition({200, 50});
    win.setVerticalSyncEnabled(true);

    /*================== Object Setup ==================*/
    std::vector<ACPoint> points;

    // sf::CircleShape myCircle(5.f);
    // myCircle.setFillColor(sf::Color(100, 250, 50));

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
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    const sf::Vector2f eventPos = sf::Vector2f(mouseButtonPressed->position);
                    for (int i = 0; i < points.size(); i++)
                    {
                        if (points[i].eventPosWithinRange(eventPos))
                        {
                            std::cout << "mouse click within position" << std::endl;
                            break;
                        }
                    }
                }
                if (mouseButtonPressed->button == sf::Mouse::Button::Right)
                {
                    ACPoint newPoint(10.f, sf::Vector2f(mouseButtonPressed->position));
                    points.push_back(newPoint);
                }
            }

            // // mouse moved
            // if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            // {
            //
            // }
            /*====================================================*/
        }


        /*================== Clear-Draw-Display ==================*/
        win.clear(sf::Color::Black);

        for (int i = 0; i < points.size(); i++)
        {
            win.draw(points[i].circle());
        }

        win.display();
        /*========================================================*/
    }
}
