#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

class Projectile
{
	protected:
		
		sf::Texture texture;
		
		sf::Vector2f velocity;
		int firedBy;
		sf::Clock fireClock;
		
	public:
		sf::Sprite sprite;
		bool isActive;
		bool firstFire;
		Projectile();
		virtual void Update(float dt);
		virtual void Draw(sf::RenderWindow &window);
		//void UpdateVelocity(float dt);

};

#endif