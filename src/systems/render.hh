#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace systems {
    void render(entt::registry &registry, sf::RenderWindow &w);
}
