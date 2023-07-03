#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Global.h"
class Tile
{
	
	public:
		bool collidable;
		bool solid;
		int sloped;
		bool isPlatform;
		int tileValue;
		int levelArrayLocation;
		int levelMapLocation;
		sf::Vector2f tilePosition;
		int gridPosition;
		//sf::RectangleShape id;
		int tileType;
		Tile();
		Tile(sf::Vector2f position);
		~Tile();
};

#endif

