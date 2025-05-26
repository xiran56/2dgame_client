#pragma once

#include <memory>

#include <SFML/Graphics/Drawable.hpp>

namespace components {
    using render = std::shared_ptr<sf::Drawable>;
}
