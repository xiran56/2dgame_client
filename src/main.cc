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

        auto wolf1 = reg.create();

        reg.emplace<components::sprite>(wolf1, player_texture);
        reg.emplace<components::position>(wolf1);

        sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

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
