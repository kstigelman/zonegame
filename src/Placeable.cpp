#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "Item.h"
#include "Placeable.h"
#include "Timer.h"

Placeable::Placeable() 
{
	lifetime = 3.f;
	lifeTimer = Timer(lifetime);
	
}
Placeable::Placeable(float time)
{
	lifetime = time;
	lifeTimer = Timer(lifetime);

}
void Placeable::Place(sf::Vector2f position)
{
	sprite.setPosition(position);
	canSwitchItem = false;
	currentlyUsed = false;
	if (lifetime > 0)
	{
		lifeTimer.ResetTimer();
		lifeTimer.StartTimer();
	}
	/*if (sf::Keyboard::isKeyPressed(useItemKey))
	{	
		canSwitchItem = false;
		currentlyUsed = false;
	}*/

}
bool Placeable::LifetimeActive()
{
	
	if (lifetime <= 0)
	{
		return false; //This item is permanent, there is no lifetime
	}
	else
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

}