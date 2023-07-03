#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Global.h"
#include "Collider.h"
#include "Item.h"
#include "Placeable.h"

class Block : public Item
{
	protected:
		bool buttonReleased;
		bool inUse;
		bool isTrap;

		char dropDirection;
		int maxBlocks;
		int totalBlocks;
		int lowerBound;
		//sf::Clock newBlockTimer;
		
	    sf::Vector2f blockPos;

		int blockSpan[2];
		void Use();
		void Gravity();
		void Drop();
	public:
		int blocksRemaining;
		//std::vector<sf::Sprite> blocks;
		Block();
		void Collision(Collider* collider);
		void Update(float dt, sf::Sprite* pSprite, Collider* collider);
		void Draw(sf::RenderWindow& window);

};
#endif