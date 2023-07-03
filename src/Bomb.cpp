#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "Block.h"
#include "Bomb.h"
#include "Placeable.h"
#include "Timer.h"


Bomb::Bomb()
{

	type = 2;
	blastZone = sf::CircleShape(64.f);
	blastZone.setOrigin(64, 64);
	sprite.setOrigin(18, 16);
	blastZone.setFillColor(sf::Color::White);
	detonateTime = 3.f;
	explodeTimer = Timer(detonateTime);
	

	exploded = false;
	isActive = true;
	ticking = false;
	texture.loadFromFile("index/assets/sprites/Bomb.png");
	sprite.setTexture(texture);
}
Bomb::~Bomb()
{
	delete pBlock;
}
void Bomb::Explode(std::vector<sf::Sprite> *blocks)
{
	//blastZone.getGlobalBounds().contains(blocks);
	for (int i = blocks->size() - 1; i > 0; i--)
	{
		if (blastZone.getGlobalBounds().contains((*blocks)[i].getPosition()))
		{

			blocks->erase(blocks->begin() + i);
			
		}

	}
	
	exploded = false;
	isActive = false;
	ticking = false;
	canSwitchItem = true;
}
void Bomb::Draw(sf::RenderWindow &window)
{
	if ((isActive == true && currentlyUsed == true) || ticking == true )
	{
		if (exploded == true)
		{
			window.draw(blastZone);
		}
		window.draw(sprite);
	}
}
void Bomb::Use()
{
	
	
}

void Bomb::Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite> *sprites)
{
	
	if (isActive == true || ticking == true)
	{

		if(currentlyUsed == true && canSwitchItem == true)
		{
			sprite.setPosition(sf::Vector2f(pSprite->getPosition().x + 50, pSprite->getPosition().y));

			if (sf::Keyboard::isKeyPressed(useItemKey))
			{
				exploded = true;
				ticking = true;
				Place(sprite.getPosition());
				
			}
			
			
		}
		else
		{
			
			blastZone.setPosition(sprite.getPosition().x, sprite.getPosition().y);
			if (exploded == true)
			{
				
				
				if (FuseTimer())
				{
					Explode(sprites);
				}
				
				
			}
		}
		
	}


}
bool Bomb::FuseTimer()
{
	lifeTimer.Update();
	if (lifeTimer.TimeOut())
	{
		return true;
	}
	else
	{
		return false;
	}

}
void Bomb::Extra()
{

	//pBlock = pPlayer->block;
}
void Bomb::ResetTimer()
{
	explodeTimer.ResetTimer();
	explodeTimer.StartTimer();
}