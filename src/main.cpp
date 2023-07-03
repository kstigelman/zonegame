/*#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}*/

/*					Project Zone
 * 	 			created by Kyler Stigelman
 *
 * Made in C++ using SFML (Simple and Fast Multimedia Library)
 * Began: 2019
 * 
 */
#include <iostream>
#include <SFML/Graphics.hpp>
//#include "pch.h"
#include "Game.h"

int 
main(int argc, char *argv[])
{
	Game game;
	game.Run();
	return EXIT_SUCCESS;
}

