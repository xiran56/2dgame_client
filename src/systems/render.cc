#include "systems/render.hh"

#include "components/sprite.hh"
#include "components/position.hh"

void systems::draw_sprites(entt::registry &registry, sf::RenderWindow &w) {
    w.clear();

    for (auto [entity, sprite, position] : registry.view<components::sprite, components::position>().each()) {
        sprite.setPosition(position);
        w.draw(sprite);
    }

    w.display();
}
