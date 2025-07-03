#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::Window win(sf::VideoMode({729, 729}), "Area Calculator");

    while (win.isOpen())
    {
        // checks all the window's events that triggered since the
        // previous iteration of the loop
        while (const std::optional event = win.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                win.close();
        }
    }
}
