#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace systems {
    void update_camera(entt::registry &registry, sf::RenderWindow &window);
}
