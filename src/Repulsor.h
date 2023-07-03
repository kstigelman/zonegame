#ifndef REPULSOR_H_INCLUDED
#define REPULSOR_H_INCLUDED


#include "Entity.h"
#include "Item.h"

class Repulsor : public Item
{
	protected:
		sf::Clock velocityClock;
		bool jumping;
		float velocity;
	public:
		Repulsor();
		virtual void Update(float dt, sf::Sprite* pSprite, Collider* collider, std::vector<sf::Sprite>* sprites);
		virtual void Use();
		void Landed(bool grounded);
		void UpdateVelocity(float speed, float dt, sf::Sprite* pSprite);

};

#endif