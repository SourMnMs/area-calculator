#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../include/ACGrid.h"
#include "../include/formulas.h"
#include "../include/ACPoint.h"
#include "../include/ACLine.h"
#include "../include/ACTriangle.h"
#include "../include/winsize.h"

/*
 * Alright this absolutely does not make sense but bear with me for a second
 * To make the built .exe runnable, go into CLion's settings
 * Build, Execution, Deployment -> ToolChains -> MinGW
 * Change the C and C++ compilers to gcc.exe and g++.exe respectively (ucrt)
 * Rebuild the project, the executable should now be runnable
 * To make it runnable within the IDE, change both of them to "Let CMake detect"
*/

int main()
{
    std::cout << "started the program" << std::endl;
    sf::RenderWindow win(sf::VideoMode(winsize::v), "Area Calculator", sf::Style::Close);
    std::cout << "made a window" << std::endl;

    // win.setPosition({200, 50});
    win.setVerticalSyncEnabled(true);

    /*================== Object Setup ==================*/
    ACGrid grid{{0, 5}, {0, 5}};

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
                        std::cout << "mouse click (" << eventPos.x << ", " << eventPos.y << ")" << std::endl;

                        const sf::Vector2f localP = grid.convertPointToLocal(eventPos);
                        std::cout << "local: (" << localP.x << ", " << localP.y << ")" << std::endl;
                    }
                }

                // right click -> make new point, set it as closest point to mouse
                if (mouseButtonPressed->button == sf::Mouse::Button::Right)
                {
                    ACPoint newPoint(5.f, sf::Vector2f(mouseButtonPressed->position), grid);
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

        // axes
        grid.draw(win);

        // point update loop
        const unsigned long long n = points.size();
        for (int i = 0; i < n; i++)
        {
            // gets point closest to mouse by checking if the point's distance
            // to the mouse is less than the current closest point's distance
            if (closestToMouse)
            {
                const sf::Vector2f pointPos = points[i].getPosition();
                const double pmDist = formulas::point::distance(pointPos, mousePos);
                const double cmDist = formulas::point::distance(closestToMouse->getPosition(), mousePos);
                if (pmDist < cmDist)
                    closestToMouse = &points[i];
            }
            win.draw(points[i].circle());

            // TO/DO: MAKE THIS ONE LINE WITH MANY SEGMENTS, NOT MULTIPLE LINES
            // if (n > 1)
            // {
            //     const ACPoint& prev = points[((i-1==-1) ? n : i) - 1];
            //     ACLine line(prev, points[i]);
            //     line.draw(win);
            // }
        }

        win.display();
        /*========================================================*/
    }
}
