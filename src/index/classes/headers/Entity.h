#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Collider.h"


class Entity
{
	private:
		
		sf::Texture texture;
	
	public:
		Collider collider;
		double movementSpeed;
		double gravitySpeed;
		double maxGravitySpeed;
		double maxSpeed;
		
		int totalVelocities;
		
		sf::Sprite sprite;
		sf::Vector2f velocity;
		sf::Vector2f externalVelocity;
		sf::Vector2f velocities[5]; // 0 - movementSpeed, 1 - gravity, 2 - modifier (Balloons), 3 - item (Bomb overrides Spring boots)
		
		bool isActive;
		Entity();
		
		//void Update(float dt/*, int* levelArray*/);
		
		virtual void Draw(sf::RenderWindow& window);
		//void Gravity(float dt);
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f position);
		void SumVelocity();
		void ApplyForces(float dt);
		void Gravity();
	
};
#endif