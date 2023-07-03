#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>
#include <iostream>

extern sf::Vector2f cameraBounds[2];
extern sf::Clock gameClock;
extern sf::Font gameFont;
extern std::vector<sf::Sprite> blocks;
extern int gameState;
extern int playerCount;


#endif 