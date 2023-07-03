#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>


#include "Global.h"
//#include "Player.h"
#include "Collider.h"

class Item
{
	protected:
		
		bool inUse;
		float useCooldown;
		sf::Clock cooldownTimer;
		sf::Time timeSince;
		
	public:
		sf::Keyboard::Key useItemKey;
		bool canSwitchItem;
		int type;
		bool currentlyUsed;
		bool isActive;
		sf::Texture texture;
		sf::Sprite sprite;
		Collider* l_Sprites; // Colliders
		Item();
		Item(std::string texturePath);
		~Item();
		virtual void Draw(sf::RenderWindow &window);
		virtual void Update(float dt, sf::Sprite *pSprite, Collider* collider, std::vector<sf::Sprite>* sprites);
		virtual void Update(float dt, sf::Sprite* pSprite, std::vector<sf::Sprite>* sprites);
		virtual void Use();
		virtual void SendGlobalSprites(Collider* m_Sprites);
		virtual void Extra();
		sf::Texture* GetTexture();
	
};

#endif
