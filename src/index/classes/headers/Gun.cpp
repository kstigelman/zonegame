#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Item.h"
#include "Gun.h"
Gun::Gun()
{
	texture.loadFromFile("index/assets/sprites/MysteryGun.png");
	sprite.setTexture(texture);
	fired = false;
	projectileActive = false;

	mode = 0;
}
void Gun::Fire()
{
	fired = true;
	srand(time(0));
	int randomNum = rand() % 100;

	if (randomNum > 50)
	{
		//50% Send projectile that knocks back enemies FAR
		projectileActive = true;
		projectile.isActive = true;
		projectile.sprite.setPosition(sprite.getPosition());
		mode = 1;
	}
	else if (randomNum > 15)
	{
		//35% Sends you flying
		mode = 2;
	}
	else
	{

		//15% CHEESE
		mode = 3;
	}

}
void Gun::Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites)
{

	if (isActive == true)
	{
		if (currentlyUsed == true && canSwitchItem == true)
		{
			sprite.setPosition(pSprite->getPosition().x + 50, pSprite->getPosition().y);
			if (sf::Keyboard::isKeyPressed(useItemKey) && fired == false)
			{
				Fire();
			}
		}
		if (mode == 1)
		{
			if (fired == true && projectileActive == true)
			{
				projectile.Update(dt);
				if (projectile.sprite.getGlobalBounds().contains(sprite.getPosition()))
				{
					projectile.isActive = false;
					
				}
			}
		}
		if (mode == 2)
		{

		}
		if (mode == 3)
		{

		}
	}
	

}
void Gun::Draw(sf::RenderWindow& window)
{
	if (isActive == true)
	{
		projectile.Draw(window);
		window.draw(sprite);
	}

}