#ifndef PLACEABLE_H_INCLUDED
#define PLACEABLE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Global.h"
#include "Item.h"
#include "Timer.h"

class Placeable : public Item
{
	protected:
		float lifetime;
		Timer lifeTimer;
	public:
		Placeable();
		Placeable(float time);
		void Place(sf::Vector2f position);
		bool LifetimeActive();
};

#endif