#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "Player.h"

sf::Vector2f cameraBounds[2];
sf::Clock gameClock;
sf::Font gameFont;
std::vector<sf::Sprite> blocks;

int gameState;
int playerCount;

