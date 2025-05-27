#include "systems/movement.hh"

#include "components/camera.hh"
#include "components/position.hh"

#include <cassert>

#include <SFML/Window/Keyboard.hpp>

constexpr float SPEED = 0.5f;

void systems::move_player(entt::registry &registry, float dt) {
    auto player_range = registry.view<components::camera, components::position>().each();
    assert(player_range.begin() != player_range.end() && "There isn't the player entity!");

    auto [entity, _, position] = *player_range.begin(); 

    using sf::Keyboard::isKeyPressed;
    using sf::Keyboard::Key;

    if (isKeyPressed(Key::W)) {
        position.y -= SPEED * dt; 
    } else if (isKeyPressed(Key::A)) {
        position.x -= SPEED * dt;
    } else if (isKeyPressed(Key::S)) {
        position.y += SPEED * dt;
    } else if (isKeyPressed(Key::D)) {
        position.x += SPEED * dt;
    }
}
