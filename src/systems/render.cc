#include "render.hh"

#include "../components/render.hh"
#include <stdexcept>

void systems::render(entt::registry &registry, sf::RenderWindow &w) {
    w.clear();

    auto view = registry.view<components::render>();

    for (auto [entity, render] : view.each()) {
        if (render == nullptr)
            throw std::runtime_error { "systems::render nullptr render component reiceved!" };

        w.draw(*render);
    }

    w.display();
}
