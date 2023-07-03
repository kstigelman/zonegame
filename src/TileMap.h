#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Global.h"
#include "Tile.h"
//TileMap class from SFML website as a reference/guide

class TileMap : public sf::Drawable, public sf::Transformable
{
	private:
		sf::VertexArray mVerticies;
		sf::Texture mTexture;
		sf::Vector2i mapSize;
		sf::Vector2i tileSizePx;
		int tileWidth;
		sf::Vector2f initPos;
		virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;
		
	public:
        TileMap();
		bool load(std::string& tileset, std::string filepath, sf::Vector2i tileSize, int* tiles, Tile* tile, int mapWidth, int mapHeight, sf::Vector2f position);
		void Update(int* tiles, sf::Vector2i tileIndex, sf::Vector2i tileLoc, int newTile);

};
#endif