#ifndef REPULSIONBOMB_H_INCLUDED
#define REPULSIONBOMB_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bomb.h"
#include "Global.h"

class RepulsionBomb : public Bomb
{
	protected:
		sf::Clock velocityClock;
		float velocity;
		float x[4];
		float y[4];
		bool jumping;
	public:
		RepulsionBomb();
		void Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites);
		void Explode();
		void UpdateVelocity(sf::Sprite* pSprite, float velocity);
		void Landed(bool grounded);
		void Use();
};

#endif