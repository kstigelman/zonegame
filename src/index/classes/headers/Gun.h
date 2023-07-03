#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Item.h"
#include "Projectile.h"

class Gun : public Item
{
	protected:
		bool fired;
		bool projectileActive;
		int mode;
		Projectile projectile;
	public:
		Gun();
		~Gun();
		void Fire();
	
		void Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites);
		void Draw(sf::RenderWindow& window);

};


#endif