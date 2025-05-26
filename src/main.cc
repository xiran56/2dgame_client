#include "SFML/Window/Keyboard.hpp"
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    sf::Window window(sf::VideoMode({800, 600}), "My window");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            if (auto key = event->getIf<sf::Event::KeyPressed>(); key != nullptr) {
                std::cout << sf::Keyboard::getDescription(key->scancode).toAnsiString() << " is pressed\n";
            }
        }
    }
}
