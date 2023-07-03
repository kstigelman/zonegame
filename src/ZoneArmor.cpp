#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"
#include "Item.h"
#include "ZoneArmor.h"

ZoneArmor::ZoneArmor()
{
	useCooldown = 5.f;
	inUse = false;
	
	texture.loadFromFile("index/assets/sprites/ZoneArmor.png");
	sprite.setTexture(texture);
}

void ZoneArmor::Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites)
{
	if (isActive == true)
	{
		std::cout << inUse << ", " << currentlyUsed << std::endl;
		if (sf::Keyboard::isKeyPressed(useItemKey) && inUse == false && currentlyUsed == true)
		{
			std::cout << "Executed\n";
			collider->zoneDamage = false;
			canSwitchItem = false;
			Use();
		}
		if (inUse == true)
		{
			std::cout << cooldownTimer.getElapsedTime().asSeconds() << std::endl;
			if (cooldownTimer.getElapsedTime().asSeconds() > useCooldown)
			{
				collider->zoneDamage = true;
				isActive = false;
				canSwitchItem = true;
				//currentlyUsed = false;
				std::cout << cooldownTimer.getElapsedTime().asSeconds() << std::endl;
			}
			else
			{
				collider->zoneDamage = false;
				
			}
		}
	}
	
}
void ZoneArmor::Use()
{
	inUse = true;
	cooldownTimer.restart();
}