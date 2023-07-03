
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>

#include "Global.h"
#include "LevelMap.h"
#include "Level.h"

		Level::Level()
		{
			int i = 0;
			numOfMaps = 7;
			mapWidth = numOfMaps;

			//k number of maps, initialize each section
			for(int k = 0; k < mapWidth; k++)
			{
				//Create filepath to load levels
				std::string filepath = "index/assets/levels/level_";
				filepath += std::to_string(k);
				filepath += ".txt";
				
				levelMap[k] = LevelMap(filepath, sf::Vector2f(1280 * k, 0));
				levelMap[k].gridPosition = sf::Vector2f(k, 0); // to be used for colliders thru a grid position to detect based on player position

				
					
			}
			
			

		}
		void Level::Draw(sf::RenderWindow &window)
		{
			for(int i = 0; i < mapWidth; i++)
			{
				if(levelMap[i].isActive == true)
				{
					levelMap[i].Draw(window);
				}
			}
		}
		sf::Vector2f Level::GetGridLocation(sf::Vector2f position)
		{
			return sf::Vector2f(floor(position.x / 1280), floor(position.y / 1280));
		}
		void Level::Update(float dt)
		{
			

		}
		void Level::GetTile()
		{


		}


