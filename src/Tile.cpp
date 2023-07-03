#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "Tile.h"



Tile::Tile()
{
	
}
Tile::Tile(sf::Vector2f position)
{
	sloped = 0;
	solid = false;
	isPlatform = false;
	//tilePosition = position;
	gridPosition = position.x / 1280; //NOT tile position. This is which section it belongs to
}

Tile::~Tile()
{
}
