#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Global.h"
#include "LevelMap.h"


class Level 
{
	
	private:
		int numOfMaps;
		
	public:
		int mapWidth;
		LevelMap levelMap[7];
		Level();
		void Draw(sf::RenderWindow &window);
		void Update(float dt);
		sf::Vector2f GetGridLocation(sf::Vector2f position);
		void GetTile();

};

#endif