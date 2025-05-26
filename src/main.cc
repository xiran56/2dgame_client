#include <SFML/Graphics/CircleShape.hpp>

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "components/render.hh"
#include "systems/render.hh"
#include <memory>

int main() {
    entt::registry reg;

    auto e = reg.create();
    
    auto circle = new sf::CircleShape { 50 };

    circle->setPosition({ 100, 100 });
    circle->setFillColor(sf::Color::Green);
    
    reg.emplace<components::render>(e, circle);
    
    auto rect = new sf::RectangleShape { { 30, 30 } };

    rect->setPosition({ 200, 200 });
    rect->setFillColor(sf::Color::Red);

    auto e2 = reg.create();
    reg.emplace<components::render>(e2, rect);

    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        systems::render(reg, window);
    }
}
