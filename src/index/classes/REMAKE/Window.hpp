#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Window
{
    private:
        int WIDTH;
        int HEIGHT;
        sf::RenderWindow window;
    public:
        Window (std::string title = "New window", int width = 1280, int height = 720) {
            window.create(title, sf::VideoMode(WIDTH, HEIGHT));
            window.setFramerateLimit (60);
        }
        sf::RenderWindow& GetWindow () {
            return window;
        }
        void setFramerate (int fps) {
            window.setFramerateLimit (fps);
        }
        bool resize (sf::Vector2i newSize) {
            wi
        }
}