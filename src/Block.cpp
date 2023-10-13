#include <SFML/Graphics.hpp>
#include <cmath>

#include "Global.h"
#include "Collider.h"
#include "Item.h"
#include "Block.h"

#include "Placeable.h"

Block::Block()
{
	blocks.push_back(sf::Sprite(sprite));
	blocks[0].setPosition(0, 5000);
	type = 1;
    lowerBound = 0;
	
	inUse = false;
	isActive = true;
	buttonReleased = true;
	useCooldown = 0.1f;
	blocksRemaining = 20;
	maxBlocks = 30;
	cooldownTimer.restart();
	
	texture.loadFromFile("index/assets/sprites/Rock.png");
	sprite.setTexture(texture);
	sprite.setPosition(1000, 500);
	sprite.setOrigin(16, 16);
	
}
void Block::Collision(Collider* collider)
{
	//Block collision is just... no...

	for (int i = 0; i < blocks.size(); i++)
	{
		if (((blocks[i].getGlobalBounds().contains(collider->hitboxPoints[2]) || blocks[i].getGlobalBounds().contains(collider->hitboxPoints[8])) && blocks[i].getGlobalBounds().contains(collider->hitboxPoints[5]))/* && blocks[i].getGlobalBounds().contains(collider->hitboxPoints[7]) != true*/)
		{
			collider->gravityActive = false;
			collider->onGround = true;
			collider->pSprite->setPosition(collider->pSprite->getPosition().x, blocks[i].getPosition().y - 46);
		}
		if (blocks[i].getGlobalBounds().contains(collider->hitboxPoints[10]) && !blocks[i].getGlobalBounds().contains(collider->hitboxPoints[5])/*|| blocks[i].getGlobalBounds().contains(collider->hitboxPoints[8]) || blocks[i].getGlobalBounds().contains(collider->hitboxPoints[10])*/)
		{
			collider->canMoveRight = false;
			collider->pSprite->setPosition(blocks[i].getPosition().x - 33, collider->pSprite->getPosition().y);
		}
		if (blocks[i].getGlobalBounds().contains(collider->hitboxPoints[9]) && !blocks[i].getGlobalBounds().contains(collider->hitboxPoints[5])/*|| blocks[i].getGlobalBounds().contains(collider->hitboxPoints[2]) || blocks[i].getGlobalBounds().contains(collider->hitboxPoints[9])*/)
		{
			collider->canMoveLeft = false;
			collider->pSprite->setPosition(blocks[i].getPosition().x + 33, collider->pSprite->getPosition().y);
		}
		if (((blocks[i].getGlobalBounds().contains(collider->hitboxPoints[0]) || blocks[i].getGlobalBounds().contains(collider->hitboxPoints[6])) && blocks[i].getGlobalBounds().contains(collider->hitboxPoints[3]))/* && blocks[i].getGlobalBounds().contains(collider->hitboxPoints[7]) != true*/)
		{
			collider->canMoveUp = false;
			collider->pSprite->setPosition(collider->pSprite->getPosition().x, blocks[i].getPosition().y + 46 + (collider->pSprite->getOrigin().y / 2));
		}
	}

}
void Block::Use()
{
	//if (sf::Keyboard::isKeyPressed(useItemKey))
	//{
		
		buttonReleased = false;
		

		if (blocksRemaining > 2)
		{
			
			if (cooldownTimer.getElapsedTime().asSeconds() >= useCooldown && inUse == false)
			{
				
				inUse = true;
				
				blocks.push_back(sf::Sprite(sprite));
				blocks.push_back(sf::Sprite(sprite));
				blocks.push_back(sf::Sprite(sprite));
				if (dropDirection == 'R')
				{
					/*for (int i = 0; i < blocks.size(); i++)
					{
						for (int j = blocks.size() - 3; j < blocks.size(); j++)
						{
							if (i != j)
							{
								if (blocks[j].getPosition() == blocks[i].getPosition())
								{
									blocks.erase(blocks.begin() + (blocks.size() - 2));
								}
							}

						}
					}*/
					blocks[blocks.size() - 1].setPosition(std::floor(blocks[blocks.size() - 1].getPosition().x / 32 - 1) * 32 - 16, std::floor(blocks[blocks.size() - 1].getPosition().y / 32) * 32 + 16);
					blocks[blocks.size() - 2].setPosition(std::floor(blocks[blocks.size() - 2].getPosition().x / 32 - 1) * 32 - 16, std::floor(blocks[blocks.size() - 2].getPosition().y / 32) * 32 - 16);
					blocks[blocks.size() - 3].setPosition(std::floor(blocks[blocks.size() - 3].getPosition().x / 32 - 1) * 32 - 16, std::floor(blocks[blocks.size() - 3].getPosition().y / 32) * 32 - 48);
				}
				else
				{
					blocks[blocks.size() - 1].setPosition(std::floor(blocks[blocks.size() - 1].getPosition().x / 32 + 1) * 32 + 16, std::floor(blocks[blocks.size() - 1].getPosition().y / 32) * 32 + 16);
					blocks[blocks.size() - 2].setPosition(std::floor(blocks[blocks.size() - 2].getPosition().x / 32 + 1) * 32 + 16, std::floor(blocks[blocks.size() - 2].getPosition().y / 32) * 32 - 16);
					blocks[blocks.size() - 3].setPosition(std::floor(blocks[blocks.size() - 3].getPosition().x / 32 + 1) * 32 + 16, std::floor(blocks[blocks.size() - 3].getPosition().y / 32) * 32 - 48);
				}
				

				cooldownTimer.restart();			
				blocksRemaining-=3;
			}
		}

	//}
	
}
void Block::Drop()
{
	/*if (buttonReleased == false)
	{
		if (!sf::Keyboard::isKeyPressed(useItemKey))
		{
			
			buttonReleased = true;
			inUse = false;
		}
	}*/
	 
}
void Block::Update(float dt, sf::Sprite* pSprite, Collider* collider)
{
	dropDirection = collider->direction;
	if (cooldownTimer.getElapsedTime().asSeconds() >= 0.7 && blocksRemaining < maxBlocks)
	{
		cooldownTimer.restart();
		blocksRemaining++;
		
	}
	
	totalBlocks = blocks.size();
	
	if(currentlyUsed == true)
	{
		if (collider->direction == 'R')
		{
			sprite.setPosition(pSprite->getPosition().x - 20, pSprite->getPosition().y);
		}
		else
		{
			sprite.setPosition(pSprite->getPosition().x + 20, pSprite->getPosition().y);
		}
		
		if (cooldownTimer.getElapsedTime().asSeconds() >= useCooldown && buttonReleased == false)
		{
			buttonReleased = true;
		}
		if (isActive == true)
		{
			if (sf::Keyboard::isKeyPressed(useItemKey) && blocksRemaining > 0)
			{
				inUse = false;
				Use();
			}
			/*if (inUse == true && buttonReleased == false)
			{
				//std::cout << "Dropping\n";
				//sprite.setPosition(pSprite->getPosition().x - 20, pSprite->getPosition().y + 30);
				Drop();
			}*/
	
		}
	}
	Collision(collider);

}
void Block::Gravity()
{


}
void Block::Draw(sf::RenderWindow &window)
{
	if (isActive == true && currentlyUsed == true)
	{
		if (blocksRemaining > 0)
		{
			window.draw(sprite);
		}
	}
	for (size_t i = 0; i < blocks.size(); i++)
	{
		window.draw(blocks[i]);
	}

}