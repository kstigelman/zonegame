
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

//#include "Global.h"

#include "Level.h"
#include "Bomb.h"
#include "Block.h"
#include "Controller.h"
//#include "Gun.h"
//#include "Item.h"
#include "Entity.h"
//#include "Collider.h"
#include "PlayerGUI.h"
#include "Repulsor.h"
//#include "RepulsionBomb.h"
#include "ZoneArmor.h"

class Player : public Entity
{
	protected:
		


		float vel;
		int playerNumber;
		bool jumping;
		bool addedMoveSpeed;
		float slope;
		float newVel;
		bool letGo;
		float switchCooldown;
		sf::Clock cooldownClock;
		int firstItem; //0 - empty, 1 - blocks, 2 - , 3 - , 4 - 
		int secondaryItem;
		int activeItem; //slot 0 or 1
		sf::Keyboard::Key controls[5];
		
		int totalSections;

		Controller controller;
	public:
	
		PlayerGUI* playerGUI;
		Item* item;
		Block* block;
		//bool zoneDamage;
		sf::Clock timePassed;
		
		
		Player();
		Player(int playerID, sf::Vector2f hbDimensions);
		~Player();
		//Player(int playerID);
		void ItemManager();
		void Update(/*sf::RenderWindow &window,*/ float dt, Level* levelMap);
		void Movement(float dt);
		void Jump();
		
		void Remove();
		void Draw(sf::RenderWindow& window);
		//void Draw(sf::RenderWindow &window);
		bool setActive(bool activity);
		float JumpVelocity(float t);
};
#endif