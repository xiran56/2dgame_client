#pragma once

#include <SFML/System/Vector2.hpp>

namespace components {
    struct transform {
        sf::Vector2i velocity, position, rectangle; 
    };
}
