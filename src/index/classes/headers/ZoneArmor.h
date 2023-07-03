#ifndef ZONEARMOR_H_INCLUDED
#define ZONEARMOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"
#include "Item.h"

class ZoneArmor : public Item
{
	protected:
		
	public:
		ZoneArmor();
		void Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites);
		
		void Use();
		
};

#endif