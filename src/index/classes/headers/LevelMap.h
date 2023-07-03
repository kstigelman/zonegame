#ifndef LEVELMAP_H_INCLUDED
#define LEVELMAP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Global.h"
#include "TileMap.h"
#include "Tile.h"


class LevelMap
{
	private:
		
		sf::Texture levelTexture;
		sf::Sprite levelSprite;
		sf::IntRect rectSource;

		TileMap map;

		float deltaTime;

		std::string levelFilePath;
		std::string tileSetFilePath;
	public:
		sf::Vector2f gridPosition;
		int width;
		int height;
		bool isActive;
		int* levelArray;
		Tile* tile;
		
		LevelMap();
		LevelMap(std::string filepath, sf::Vector2f position);

		
		void Draw(sf::RenderWindow &window);
		void Update(float dt);
	
};
#endif