#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Global.h"
#include "Tile.h"
#include "TileMap.h"
//TileMap class from SFML website as a reference/guide


	    void TileMap::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
		{
			
			renderStates.transform *= getTransform();
			renderStates.texture = &mTexture;
			renderTarget.draw(mVerticies, renderStates);
		}
        TileMap::TileMap()
		{
			//initPos = sf::Vector2f(0, 0);
			
		}
		bool TileMap::load(std::string& tileset, std::string filepath, sf::Vector2i tileSize, int* tiles, Tile* tile, int mapWidth, int mapHeight, sf::Vector2f position)
		{
			initPos = position;
			mapSize = sf::Vector2i(mapWidth, mapHeight);
			tileSizePx = tileSize;
			
			int tileWidth = 4;
			std::ifstream Input;
			
			char* readArray = new char[mapWidth * mapHeight];

			if(!mTexture.loadFromFile(tileset)) //Loads TileSet texture
			{
				return false;
			}
			mVerticies.setPrimitiveType(sf::Quads);
			mVerticies.resize(mapWidth * mapHeight * tileWidth);

			Input.open(filepath);
			
			std::cout << filepath << "\n";
			for(int j = 0; j < mapHeight; j++)
			{
				for(int i = 0; i < mapWidth; i++)
				{
					Input >> readArray[i + j * mapWidth];
					
					tile[i + j * mapWidth].tilePosition = sf::Vector2f(i, j);
					if(readArray[i + j * mapWidth] == '0')
					{
						tiles[i + j * mapWidth] = 0;
						tile[i + j * mapWidth].tileValue = 0;
					}
					else if(readArray[i + j * mapWidth] == '1')
					{
						tiles[i + j * mapWidth] = 1;
						tile[i + j * mapWidth].tileValue = 1;
					}
					else if(readArray[i + j * mapWidth] == '2')
					{
						tiles[i + j * mapWidth] = 2;
						tile[i + j * mapWidth].tileValue = 2;
					}
					else if(readArray[i + j * mapWidth] == '3')
					{
						tiles[i + j * mapWidth] = 3;
						tile[i + j * mapWidth].tileValue = 3;
						
					}
					else if(readArray[i + j * mapWidth] == '4')
					{
						tiles[i + j * mapWidth] = 4;
						tile[i + j * mapWidth].tileValue = 4;
					}
					else if(readArray[i + j * mapWidth] == '5')
					{
						tiles[i + j * mapWidth] = 5;
						tile[i + j * mapWidth].tileValue = 5;
					}
					else if(readArray[i + j * mapWidth] == '6')
					{
						tiles[i + j * mapWidth] = 6;
						tile[i + j * mapWidth].tileValue = 6;
					}
					else if(readArray[i + j * mapWidth] == '7')
					{
						tiles[i + j * mapWidth] = 7;
						tile[i + j * mapWidth].tileValue = 7;
					}
					else if(readArray[i + j * mapWidth] == '8')
					{
						tiles[i + j * mapWidth] = 8;
						tile[i + j * mapWidth].tileValue = 8;
					}
					else if(readArray[i + j * mapWidth] == '9')
					{
						tiles[i + j * mapWidth] = 9;
						tile[i + j * mapWidth].tileValue = 9;
					}
					else {
						tiles[i + j * mapWidth] = 0;
						tile[i + j * mapWidth].tileValue = 0;
					}
					if (tile[i + j * mapWidth].tileValue != 0)
					{
						tile[i + j * mapWidth].solid = true;
					}
					if (tile[i + j * mapWidth].tileValue == 3)
					{

						tile[i + j * mapWidth].isPlatform = true;
						tile[i + j * mapWidth].solid = false;
					}
				
					int nTileCount = tile[i + j * mapWidth].tileValue;

					int tMod = nTileCount % (mTexture.getSize().x / tileSize.x);
					int tDivd = nTileCount / (mTexture.getSize().x / tileSize.x);

					sf::Vertex* quad = &mVerticies[(i + j * mapWidth) * tileWidth];

					quad[0].position = sf::Vector2f(i * tileSize.x + initPos.x, j * tileSize.y + initPos.y); 
					quad[1].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
					quad[2].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);
					quad[3].position = sf::Vector2f(i* tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);

					quad[0].texCoords = sf::Vector2f(tMod * tileSize.x, tDivd * tileSize.y);
					quad[1].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, tDivd * tileSize.y);
					quad[2].texCoords = sf::Vector2f((tMod+1) * tileSize.x, (tDivd + 1) * tileSize.y);
					quad[3].texCoords = sf::Vector2f(tMod * tileSize.x, (tDivd + 1) * tileSize.y);

					if (tile[i + j * mapWidth].tileValue == 3)
					{
						quad[0].texCoords = sf::Vector2f(tMod * tileSize.x, tDivd * tileSize.y);
						quad[1].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, tDivd * tileSize.y);
						quad[2].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, ((tDivd + 1) * tileSize.y));
						quad[3].texCoords = sf::Vector2f(tMod * tileSize.x, ((tDivd + 1) * tileSize.y));
					}
				}
			}
			for (int j = 1; j < mapHeight - 1; j++)
			{
				for (int i = 1; i < mapWidth - 1; i++)
				{
					if (tile[i + j * mapWidth].tileValue != 0 && tile[(i - 1) + (j + 1) * mapWidth].tileValue != 0 && tile[(i - 1) + j * mapWidth].tileValue == 0 && tile[i + (j - 1) * mapWidth].tileValue == 0)
					{
						tile[i + j * mapWidth].sloped = 1;
						tile[i + j * mapWidth].solid = false;
						int nTileCount = tile[i + j * mapWidth].tileValue;

						int tMod = nTileCount % (mTexture.getSize().x / tileSize.x);
						int tDivd = nTileCount / (mTexture.getSize().x / tileSize.x);

						sf::Vertex* quad = &mVerticies[(i + j * mapWidth) * tileWidth];

						quad[0].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
						quad[1].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);
						quad[3].position = sf::Vector2f(i * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);

					}
					
					
					if (tile[i + j * mapWidth].tileValue != 0 && tile[(i + 1) + (j + 1) * mapWidth].tileValue != 0 && tile[(i + 1) + j * mapWidth].tileValue == 0 && tile[i + (j - 1) * mapWidth].tileValue == 0)
					{

						tile[i + j * mapWidth].sloped = 2;
						tile[i + j * mapWidth].solid = false;
						int nTileCount = tile[i + j * mapWidth].tileValue;

						int tMod = nTileCount % (mTexture.getSize().x / tileSize.x);
						int tDivd = nTileCount / (mTexture.getSize().x / tileSize.x);

						sf::Vertex* quad = &mVerticies[(i + j * mapWidth) * tileWidth];

						quad[0].position = sf::Vector2f(i * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
						quad[1].position = sf::Vector2f(i * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);
						quad[3].position = sf::Vector2f(i * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);

					}
				}

			}
			/*for (int j = 1; j < mapHeight - 1; j++)
			{
				for (int i = 1; i < mapWidth - 1; i++)
				{
					if (tile[i + j * mapWidth].solid == true && (tile[(i-1) + (j-1) * mapWidth].tileValue == tile[i + j * mapWidth].tileValue || tile[(i+1) + (j+1) * mapWidth].tileValue == tile[i + j * mapWidth].tileValue) && tile[(i+1) + j * mapWidth].tileValue == 0 && tile[i + (j-1) * mapWidth].tileValue == 0)
					{
						tile[i + j * mapWidth].sloped = true;
						tile[i + j * mapWidth].solid = false;

						int nTileCount = tile[i + j * mapWidth].tileValue;

						int tMod = nTileCount % (mTexture.getSize().x / tileSize.x);
						int tDivd = nTileCount / (mTexture.getSize().x / tileSize.x);

						sf::Vertex* quad = &mVerticies[(i + j * mapWidth) * tileWidth];

						quad[0].position = sf::Vector2f(i * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
						quad[1].position = sf::Vector2f((i + 0.5) * tileSize.x + initPos.x, (j + 0.5) * tileSize.y + initPos.y);
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);
						quad[3].position = sf::Vector2f(i* tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);

						quad[0].texCoords = sf::Vector2f(tMod * tileSize.x, tDivd * tileSize.y);
						quad[1].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, tDivd * tileSize.y);
						quad[2].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, (tDivd + 1) * tileSize.y);
						quad[3].texCoords = sf::Vector2f(tMod * tileSize.x, (tDivd + 1) * tileSize.y);
					}
					else if (tile[i + j * mapWidth].tileValue != 0 && (tile[(i - 1) + (j + 1) * mapWidth].tileValue == tile[i + j * mapWidth].tileValue || tile[(i + 1) + (j - 1) * mapWidth].tileValue == tile[i + j * mapWidth].tileValue) && tile[(i - 1) + j * mapWidth].tileValue == 0 && tile[i + (j - 1) * mapWidth].tileValue == 0)
					{
						tile[i + j * mapWidth].sloped = true;

						int nTileCount = tile[i + j * mapWidth].tileValue;

						int tMod = nTileCount % (mTexture.getSize().x / tileSize.x);
						int tDivd = nTileCount / (mTexture.getSize().x / tileSize.x);

						sf::Vertex* quad = &mVerticies[(i + j * mapWidth) * tileWidth];

						quad[0].position = sf::Vector2f((i + 0.5) * tileSize.x + initPos.x, (j + 0.5) * tileSize.y + initPos.y);
						quad[1].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, j * tileSize.y + initPos.y);
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);
						quad[3].position = sf::Vector2f(i* tileSize.x + initPos.x, (j + 1) * tileSize.y + initPos.y);

						quad[0].texCoords = sf::Vector2f(tMod * tileSize.x, tDivd * tileSize.y);
						quad[1].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, tDivd * tileSize.y);
						quad[2].texCoords = sf::Vector2f((tMod + 1) * tileSize.x, (tDivd + 1) * tileSize.y);
						quad[3].texCoords = sf::Vector2f(tMod * tileSize.x, (tDivd + 1) * tileSize.y);
					}
				}
			}*/
			return true;
		}
		void TileMap::Update(int* tiles, sf::Vector2i tileIndex, sf::Vector2i tileLoc, int newTile)
		{
			//tiles[tileIndex.x + tileIndex.y * mapSize.x]	
					int nTileCount = newTile;

					int tMod = nTileCount % (mTexture.getSize().x / tileSizePx.x);
					int tDivd = nTileCount / (mTexture.getSize().x / tileSizePx.x);

					sf::Vertex* quad = &mVerticies[(tileIndex.x + tileIndex.y * mapSize.x) * tileWidth];

					quad[0].position = sf::Vector2f(tileIndex.x * tileSizePx.x + initPos.x, tileIndex.y * tileSizePx.y + initPos.y);
					quad[1].position = sf::Vector2f((tileIndex.x + 1) * tileSizePx.x + initPos.x, tileIndex.y * tileSizePx.y + initPos.y);
					quad[2].position = sf::Vector2f((tileIndex.x + 1) * tileSizePx.x + initPos.x, (tileIndex.y + 1) * tileSizePx.y + initPos.y);
					quad[3].position = sf::Vector2f(tileIndex.x * tileSizePx.x + initPos.x, (tileIndex.y + 1) * tileSizePx.y + initPos.y);

					quad[0].texCoords = sf::Vector2f(tMod * tileSizePx.x, tDivd * tileSizePx.y);
					quad[1].texCoords = sf::Vector2f((tMod + 1) * tileSizePx.x, tDivd * tileSizePx.y);
					quad[2].texCoords = sf::Vector2f((tMod+1) * tileSizePx.x, (tDivd + 1) * tileSizePx.y);
					quad[3].texCoords = sf::Vector2f(tMod * tileSizePx.x, (tDivd + 1) * tileSizePx.y);
			
		}
