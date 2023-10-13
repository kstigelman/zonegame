#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

#include "Global.h"
#include "Controller.h"
#include "Player.h"
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

Player::Player()
{

}
Player::Player(int playerID, sf::Vector2f hbDimensions)
{
	
	velocity = sf::Vector2f(0, 0);
	addedMoveSpeed = false;
	switchCooldown = 0.5f;
	playerNumber = playerID;
	collider.hitboxDimensions = hbDimensions;

	//totalSections = int(floor(hbDimensions.x / 32) + 2) * floor((hbDimensions.y / 32) + 2);
	collider.gravitySpeed = gravitySpeed;
	isActive = true;
	jumping = false;
	letGo = false;
	
	sprite.setOrigin(20, 30);

	switch (playerID)
	{
		case 1:
			
			sprite.setPosition(200, 300);
			controls[0] = sf::Keyboard::W;
			controls[1] = sf::Keyboard::A;
			controls[2] = sf::Keyboard::S;
			controls[3] = sf::Keyboard::D;
			controls[4] = sf::Keyboard::E;
			break;
		case 2:
			sprite.setPosition(400, 300);
			controls[0] = sf::Keyboard::Up;
			controls[1] = sf::Keyboard::Left;
			controls[2] = sf::Keyboard::Down;
			controls[3] = sf::Keyboard::Right;
			controls[4] = sf::Keyboard::RControl;
			break;
		case 3:
			sprite.setPosition(600, 300);
			controls[0] = sf::Keyboard::I;
			controls[1] = sf::Keyboard::J;
			controls[2] = sf::Keyboard::K;
			controls[3] = sf::Keyboard::L;
			controls[4] = sf::Keyboard::O;
			break;
		case 4:
			sprite.setPosition(800, 300);
			controls[0] = sf::Keyboard::Numpad8;
			controls[1] = sf::Keyboard::Numpad4;
			controls[2] = sf::Keyboard::Numpad5;
			controls[3] = sf::Keyboard::Numpad6;
			controls[4] = sf::Keyboard::Numpad9;
			break;

	}
	
	block = new Block;
	item = new ZoneArmor;//RepulsionBomb;
	playerGUI = new PlayerGUI{ playerID };

	item->useItemKey = controls[4];
	block->useItemKey = controls[4];

	collider.SetSprite(&sprite);
	switch (playerNumber)
	{
		case 1:
			sprite.setColor(sf::Color::Blue);
			break;
		case 2:
			sprite.setColor(sf::Color::Red);
			break;
		case 3:
			sprite.setColor(sf::Color::Green);
			break;
		case 4:
			sprite.setColor(sf::Color::Yellow);
			break;
		default:
			sprite.setColor(sf::Color::White);
			break;

	}
	
}
Player::~Player()
{
	delete playerGUI;
	delete item;
	delete block;
}
void Player::Draw(sf::RenderWindow& window)
{
	//collider.SetSprite(&sprite);
	window.draw(sprite);
	item->Draw(window);
	block->Draw(window);
	
	//window.draw(collider.hitbox);

}
void Player::Update(/*sf::RenderWindow &window, */float dt, Level* levelMap)
{
	
	if (isActive == true)
	{
		

		Movement(dt);
		Gravity();
		ItemManager();

		//New collider method
		
		int sections = levelMap->mapWidth;
		collider.Update(dt, velocities[1], levelMap, &sprite);

		/*Tile* temp_tile;
		for (int i = 0; i < totalSections; i++)
		{
			temp_tile = &levelMap->levelMap[int(floor(collider.collisionPoints[i].x) / 40)].tile[int(floor(int(collider.collisionPoints[i].x) % 40) + floor(int(collider.collisionPoints[i].y) % 40) * 40)];
			collider.NewCollision(temp_tile->id, temp_tile->tileValue, 1);
			
		}
		temp_tile = NULL;
		delete temp_tile;*/
		//sprite.setPosition(collider.hitbox.getPosition());
		
		
		block->Update(dt, &sprite, &collider);
		item->Update(dt, &sprite, &collider, &blocks);
		
		if (activeItem == 0)
		{
			playerGUI->Update(block->GetTexture(), item->GetTexture(), block->blocksRemaining, 0);
		}
		else
		{
			playerGUI->Update(item->GetTexture(), block->GetTexture(), block->blocksRemaining, 1);
		}
	}
			
}
void Player::Movement(float dt)
{
	
	if (collider.onGround == true)
	{
		movementSpeed = 0.45f;
		velocities[1].y = 0;
	}
	else
	{
		movementSpeed = 0.3f;
	}
	if (jumping == true)
	{
		if (collider.canMoveUp == false)
		{
			jumping = false;

		}
	
		if (collider.gravityActive == false)
		{
			
			jumping = false;
		}
		
		float yVel = JumpVelocity(timePassed.getElapsedTime().asSeconds());
		velocities[1].y = yVel;
		
		
	}
	
	if (sf::Keyboard::isKeyPressed(controls[0]))
	{
		if ( jumping == false && collider.onGround == true)
		{
			Jump();
		}
	}
	else
	{
		
	}

	if (sf::Keyboard::isKeyPressed(controls[1]) && collider.canMoveLeft == true)
	{
			
		velocities[0].x = -movementSpeed;
		collider.direction = 'L';
			
	}
	else if (sf::Keyboard::isKeyPressed(controls[3]) && collider.canMoveRight == true)
	{
			
			velocities[0].x = movementSpeed;
				
			
		collider.direction = 'R';
		//sprite.move(movementSpeed * dt, 0);
			

	}
	else
	{
			
			velocities[0].x = 0;
			
	}
	
	sprite.move(velocities[0].x * dt, velocities[1].y * dt);

	//SumVelocity();
	//collider.movementVelocity = velocity;
	//collider.Move();
	//ApplyForces(dt);
	
}
void Player::Jump()
{
	if (jumping == false)
	{	
		timePassed.restart();
		jumping = true;
	}
}
void Player::Remove() //Remove player from arena when out
{


}
bool Player::setActive(bool activity)
{
	isActive = activity;
	return activity;
}
void Player::ItemManager()
{
	if (item->isActive == false)
	{
		item = new Item();
		
		srand(time(0));
		int itemClass = rand() % 100;
		int itemStyle;
		if (itemClass < 60)
		{
			if (itemClass < 25)
			{
				//Protection
				srand(time(0));
				itemStyle = rand() % 100;
				if (itemStyle < 75)
				{
					item = new ZoneArmor();
					std::cout << "Zone armor" << std::endl;


				}
				else
				{
					//item = new MetalBoots;
					item = new ZoneArmor();
					std::cout << "metalBoots" << std::endl;
				}
				item->isActive = true;
			}
			else
			{
				//Destruction
				srand(time(0));
				itemStyle = rand() % 10;
				if (itemStyle <= 4)
				{
					//item = new Firework;
					
					item = new Bomb();
					
					std::cout << "firework" << std::endl;
				}
				else
				{
					
					item = new Bomb();
					std::cout << "bomb" << std::endl;
				}
				item->isActive = true;
			}
		}
		else
		{
			//Mobility
			srand(time(0));
			itemStyle = rand() % 10;
			if (itemStyle <= 5)
			{
				item = new Repulsor;
				
				std::cout << "repulsor" << std::endl;
				item->isActive = false;
			}
			else
			{
				item = new Repulsor;
			
				std::cout << "tether" << std::endl;
				item->isActive = false;
			}
			item->isActive = true; // REMOVE COMMENT WHEN MOBILITY IS ADDED
		}
		item->useItemKey = controls[4];
		if (activeItem == 1)
		{
			item->currentlyUsed = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(controls[2]))  
	{
		if (cooldownClock.getElapsedTime().asSeconds() > switchCooldown)
		{
			switch (activeItem)
			{
			case 0:
				activeItem = 1;
				block->currentlyUsed = false;
				//block->isActive = false;
				item->currentlyUsed = true;
				//item->isActive = true;
				std::cout << activeItem << std::endl;
				break;
			case 1:
				activeItem = 0;
				item->currentlyUsed = false;
				//item->isActive = false;
				block->currentlyUsed = true;
			//	block->isActive = true;
				std::cout << activeItem << std::endl;
				break;
			}
			cooldownClock.restart();
		}
	}
	
}
float Player::JumpVelocity(float t)
{
	//float vel;// = (-gravitySpeed * t) + (0.10286 * 7);  //0.10286
	if ((-gravitySpeed * t) + (0.10286 * 7) > -0.8)
	{
		//vel = (-gravitySpeed * t) + (0.10286 * 7);
		vel = (-gravitySpeed * t) + (0.06 * 9);
	}
	
	return -vel;
}