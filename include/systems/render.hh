#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace systems {
    void draw_sprites(entt::registry &registry, sf::RenderWindow &w);
}
