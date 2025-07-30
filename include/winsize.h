//
// Created by Theodore on 7/16/2025.
//

#ifndef WINSIZE_H
#define WINSIZE_H

#include "ACGrid.h"
#include "SFML/System/Vector2.hpp"

namespace winsize
{
    constexpr unsigned int width = 729;
    constexpr unsigned int height = 729;
    constexpr sf::Vector2 v{width, height};
    constexpr sf::Vector2i vi{width, height};
    constexpr sf::Vector2f vf{width, height};
}

#endif //WINSIZE_H
