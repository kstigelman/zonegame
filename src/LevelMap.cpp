#include <SFML/Graphics.hpp>
#include "Global.h"
#include "TileMap.h"
#include "Tile.h"
#include "LevelMap.h"


		LevelMap::LevelMap()
		{
			width = 40;
			height = 40;
			isActive = true;
			levelArray = new int[width * height];
			tile = new Tile[width * height];
			tileSetFilePath = "index/assets/sprites/Tiles.png";
			
		}
		LevelMap::LevelMap(std::string filepath, sf::Vector2f position)
		{
			gridPosition = sf::Vector2f(floor(position.x / 1280), floor(position.y / 1280));
			width = 40;
			height = 40;
			
			isActive = true;


			//initialize level array 
			levelArray = new int[width * height]; 
			
			//Initialize tile array. 
			//position shows which section the tile belongs to. NOT the same as tile position, which comes later
			tile = new Tile[width * height]{position}; 
			


			for (int j = 0; j < height; j++)
			{
				for (int i = 0; i < width; i++)
				{
					tile[i + j * height].tilePosition = sf::Vector2f(position.x + (i * 32), position.y + (j * 32)); //Now we initialize where all the tiles are located
				}
			}
			tileSetFilePath = "index/assets/sprites/Zone.png";
			map.load(tileSetFilePath, filepath, sf::Vector2i(32, 32), levelArray, tile, width, height, position); //load TileMap

		}

		
		void LevelMap::Draw(sf::RenderWindow &window)
		{
			window.draw(map);
		}
		void LevelMap::Update(float dt)
		{
			deltaTime = dt;
			int tilePath = 3;
			//map.Update(levelArray, sf::Vector2i(3, 10), sf::Vector2i(0, 0), tilePath);

		}
	

