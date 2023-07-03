#include <SFML/Graphics.hpp>


#include "Entity.h"
#include "Item.h"
#include "Repulsor.h"

Repulsor::Repulsor()
{
	inUse = false;
	jumping = false;
	texture.loadFromFile("index/assets/sprites/Repulsor.png");
	sprite.setTexture(texture);


}
void Repulsor::Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites)
{
	if (isActive == true)
	{

		if (sf::Keyboard::isKeyPressed(useItemKey) && inUse == false && currentlyUsed == true && jumping == false && collider->onGround == true)
		{
	
			canSwitchItem = false;
			collider->onGround = false;
			Use();

			
		}
		if (inUse == true && jumping == true)
		{
			UpdateVelocity(collider->gravitySpeed, dt, pSprite);
			Landed(collider->onGround);
			
		}
		
	}
}
void Repulsor::Landed(bool grounded)
{
	if (grounded == true)
	{
		inUse = false;
		jumping = false;
		isActive = false;
	}
}
void Repulsor::UpdateVelocity(float speed, float dt, sf::Sprite *pSprite)
{
	float t = velocityClock.getElapsedTime().asSeconds();
	velocity = (-speed * t) + (0.25 * 7.6);
	pSprite->move(sf::Vector2f(0.0, -velocity * dt));
	
}
void Repulsor::Use()
{
	inUse = true;
	jumping = true;
	
	velocityClock.restart();
	
}