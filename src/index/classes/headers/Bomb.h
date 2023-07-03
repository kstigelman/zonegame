#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "Placeable.h"
#include "Block.h"
#include "Timer.h"


class Bomb : public Placeable
{
	protected:
		
		sf::CircleShape blastZone;
		Timer explodeTimer;
		float detonateTime;
		bool exploded;
		bool inUse;
		bool ticking;
		std::vector<sf::Sprite>* m_sprites;
	public:
		Item* pBlock;
		Bomb();
		~Bomb();
		void Use();
		virtual void Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite> *sprites);
		virtual void Draw(sf::RenderWindow &window);
		void Extra(/*Player* pPlayer*/);

		virtual void Explode(std::vector<sf::Sprite>* blocks);
		bool FuseTimer();
		void ResetTimer();
};
#endif
