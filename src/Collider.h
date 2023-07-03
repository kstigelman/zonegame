#ifndef COLLIDER_H_INCLUDED
#define COLLIDER_H_INCLUDED


#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "LevelMap.h"
#include "Level.h"
#include "Tile.h"

class Collider
{
	private:
		
		Tile inLevelMap[12];
		sf::Vector2f lastPositions[10];
		float deltaTime;
		
	public:
		float gravitySpeed;
		float movementSpeed;
		sf::RectangleShape hitbox;
		sf::Vector2f hitboxDimensions;
		sf::FloatRect collisionHitbox;

		sf::Vector2f collisionPoints[12];
		sf::Vector2f hitboxPoints[12];

		sf::Vector2f hitboxVel;

		sf::Vector2f movementVelocity;


		//Necessary Variables for NewCollision
		
		//int canMove[4];

		//Variable for movement
		sf::Sprite* pSprite;
		char direction;
		bool canMoveLeft;
		bool canMoveRight;
		bool canMove;
		bool gravityActive;
		bool canMoveUp;
		bool onGround;
		bool zoneDamage;
		bool isColliding();
		void Update(float dt, sf::Vector2f velocity, Level* level, sf::Sprite* sprite);
		void Move();
		void Collision(float dt, Level* level, sf::Sprite* sprite);
		void NewCollision(sf::RectangleShape target, int targetProperty, int collisionType);
		void ApplyVelocity(sf::Vector2f velocity, float duration);
		void SetSprite(sf::Sprite* p_sprite);
		float GetVelocity();
		
		sf::Vector2f GetPosition();
		Collider();
		~Collider();
		//Collider(sf::Vector2f dimensions);
	

};
#endif