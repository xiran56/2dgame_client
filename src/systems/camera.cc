#include "systems/camera.hh"

#include "components/camera.hh"
#include "components/position.hh"

#include <cassert>

void systems::update_camera(entt::registry &registry, sf::RenderWindow &window) {
    auto cameras_range = registry.view<components::camera, components::position>().each();
    assert(cameras_range.begin() != cameras_range.end() && "There isn't a player entity with following components: camera, transform");
    
    auto [entity, camera, position] = *cameras_range.begin();
    camera.setCenter(position);
    window.setView(camera);
}
