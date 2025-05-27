#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Clock.hpp"
#include "components/camera.hh"
#include "components/position.hh"
#include "components/sprite.hh"
#include "systems/movement.hh"
#include "systems/render.hh"
#include "systems/camera.hh"

#include <SFML/Graphics/Texture.hpp>
#include <iostream>


int main() {
    try {
        entt::registry reg;

        auto player_entity = reg.create();

        sf::Texture player_texture { "..\\res\\hero.png", false, sf::IntRect{{0,192}, {96,96}} };

        reg.emplace<components::sprite>(player_entity, player_texture);
        reg.emplace<components::position>(player_entity);
        reg.emplace<components::camera>(player_entity);

        for (int i = 0; i < 10; i++) {
            auto wolf = reg.create();
            components::sprite wolf_sprite { player_texture };
            wolf_sprite.setColor(sf::Color::Red);

            reg.emplace<components::sprite>(wolf, wolf_sprite);
            reg.emplace<components::position>(wolf, components::position{static_cast<float>(i * 200), 0});
        }

        sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

        window.setVerticalSyncEnabled(true);

        sf::Clock clock;

        while (window.isOpen()) {
            float dt = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            dt /= 800;

            while (const auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            systems::move_player(reg, dt);
            systems::update_camera(reg, window);
            systems::draw_sprites(reg, window);
        }
    } catch (const std::exception &ex) {
        std::cout << "An exception has  occured!"
                  << "what(): " << ex.what() << std::endl;
    }
}
