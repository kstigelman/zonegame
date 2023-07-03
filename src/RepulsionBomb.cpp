

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bomb.h"
#include "Global.h"
#include "RepulsionBomb.h"

RepulsionBomb::RepulsionBomb()
{
	//blastZone = sf::CircleShape(128.f);
	texture.loadFromFile("index/assets/sprites/Repulse.png");
	sprite.setTexture(texture);
	isActive = true;
	ticking = true;
	velocity = 1;
}
void RepulsionBomb::Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites)
{
	if (isActive == true || ticking == true)
	{
		
			if (currentlyUsed == true && canSwitchItem == true)
			{
				sprite.setPosition(sf::Vector2f(pSprite->getPosition().x + 50, pSprite->getPosition().y));
				std::cout << "moving...\n";
				if (sf::Keyboard::isKeyPressed(useItemKey))
				{
					std::cout << "placed\n";
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
						Explode();
					}

				}
			}

		}
		if (inUse == true && jumping == true)
		{
			
		}
	

}
void RepulsionBomb::Explode()
{
	
	exploded = false;
	ticking = false;
	canSwitchItem = true;

	for (int i = 0; i < playerCount; i++)
	{
		if (l_Sprites[i].hitbox.getPosition().x - sprite.getPosition().x < 128)
		{
			std::cout << "Exploded\n";
			x[i] = velocity;// * //std::cos(l_Sprites[i].hitbox.getPosition().x - sprite.getPosition().x);
			y[i] = velocity; //* std::sin(l_Sprites[i].hitbox.getPosition().y - sprite.getPosition().y);
			l_Sprites[i].ApplyVelocity(sf::Vector2f(x[i], y[i]), 0);
			
		}
	}

}
void RepulsionBomb::UpdateVelocity(sf::Sprite* pSprite, float velocity)
{

}
void RepulsionBomb::Landed(bool grounded)
{
	if (grounded == true)
	{
		inUse = false;
		jumping = false;
	}
}
void RepulsionBomb::Use()
{
	inUse = true;
	jumping = true;
	velocityClock.restart();
}