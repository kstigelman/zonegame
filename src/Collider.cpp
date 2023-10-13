
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Global.h"
#include "Collider.h"
#include "LevelMap.h"
#include "Level.h"
#include "Tile.h"

Collider::~Collider()
{
	delete pSprite;
}
    bool  Collider::isColliding()
	{
		return true;
	}
	float Collider::GetVelocity()
	{
		return std::sqrt(std::pow(hitboxVel.x, 2) + (hitboxVel.y, 2));
	}
	sf::Vector2f Collider::GetPosition()
	{
		return hitbox.getPosition();
	}
    void  Collider::Update(float dt, sf::Vector2f velocity, Level* level, sf::Sprite* sprite)
	{
		
		pSprite = sprite;
		hitbox.setPosition(sprite->getPosition());
		hitboxVel = velocity;
		hitboxPoints[0] = sf::Vector2f(hitbox.getPosition().x - (hitboxDimensions.x / 2), hitbox.getPosition().y - (hitboxDimensions.y / 2));
		hitboxPoints[1] = sf::Vector2f(hitbox.getPosition().x - (hitboxDimensions.x / 2), hitbox.getPosition().y);
		hitboxPoints[2] = sf::Vector2f(hitbox.getPosition().x - (hitboxDimensions.x / 2), hitbox.getPosition().y + (hitboxDimensions.y / 2));
		hitboxPoints[3] = sf::Vector2f(hitbox.getPosition().x, hitbox.getPosition().y - (hitboxDimensions.y / 2));
		hitboxPoints[4] = sf::Vector2f(hitbox.getPosition().x, hitbox.getPosition().y);
		hitboxPoints[5] = sf::Vector2f(hitbox.getPosition().x, hitbox.getPosition().y + (hitboxDimensions.y / 2));
		hitboxPoints[6] = sf::Vector2f(hitbox.getPosition().x + (hitboxDimensions.x / 2), hitbox.getPosition().y - (hitboxDimensions.y / 2));
		hitboxPoints[7] = sf::Vector2f(hitbox.getPosition().x + (hitboxDimensions.x / 2), hitbox.getPosition().y);
		hitboxPoints[8] = sf::Vector2f(hitbox.getPosition().x + (hitboxDimensions.x / 2), hitbox.getPosition().y + (hitboxDimensions.y / 2));
		hitboxPoints[9] = sf::Vector2f(hitbox.getPosition().x - (hitboxDimensions.x / 2), hitbox.getPosition().y + (hitboxDimensions.y / 4));
		hitboxPoints[10] = sf::Vector2f(hitbox.getPosition().x + (hitboxDimensions.x / 2), hitbox.getPosition().y + (hitboxDimensions.y / 4));
		
		for (int i = 0; i < 11; i++)
		{
			collisionPoints[i] = sf::Vector2f(floor(hitboxPoints[i].x / 32), floor(hitboxPoints[i].y / 32) );
		}
		
		for (int i = 0; i < 12; i++)
		{

			int levelArrayIndex = floor(int(collisionPoints[i].x) % 40) + floor(int(collisionPoints[i].y) % 40) * 40;
			int levelMapIndex = floor(int(collisionPoints[i].x) / 40);
			inLevelMap[i] = level->levelMap[levelMapIndex].tile[levelArrayIndex];
			//inLevelMap[i] = level->levelMap[levelMapIndex].gridPosition.x;
						
		}
		hitbox.setPosition(sprite->getPosition());
		Collision(dt, level, sprite);
		
		lastPositions[0] = hitbox.getPosition();

		for (int i = 0; i < 9; i++)
		{
			lastPositions[9 - i] = lastPositions[9 - i - 1];
		}
	}
	void Collider::Collision(float dt, Level* level, sf::Sprite* sprite)
	{
		deltaTime = dt;
		if (inLevelMap[4].sloped == 1 || inLevelMap[5].sloped == 1)
		{
			if (inLevelMap[4].sloped == 1)
			{
				if (sprite->getPosition().y > (inLevelMap[4].tilePosition.y * 32) - (int(sprite->getPosition().x) % 32))
				{
					onGround = true;
					gravityActive = false;
					sprite->setPosition(sprite->getPosition().x, (inLevelMap[4].tilePosition.y * 32) - (int(sprite->getPosition().x) % 32));
				}
				else
				{
					onGround = false;
					gravityActive = true;
				}
			}
			else if(inLevelMap[5].sloped == 1)
			{
				if(sprite->getPosition().y > (inLevelMap[5].tilePosition.y * 32) - (int(sprite->getPosition().x) % 32))
				{
					onGround = true;
					gravityActive = false;
					sprite->setPosition(sprite->getPosition().x, (inLevelMap[5].tilePosition.y * 32) - (int(sprite->getPosition().x) % 32));
				}
				else
				{
					onGround = false;
					gravityActive = true;
				}
				
			}
			
		}
		else if (inLevelMap[4].sloped == 2 || inLevelMap[5].sloped == 2) //For some unknown reason removing - 1 does not seem to work?
		{
			if (inLevelMap[4].sloped == 2)
			{
				if (sprite->getPosition().y > ((inLevelMap[4].tilePosition.y - 1) * 32) + (int(sprite->getPosition().x) % 32))
				{
					onGround = true;
					gravityActive = false;
					sprite->setPosition(sprite->getPosition().x, ((inLevelMap[4].tilePosition.y - 1) * 32) + (int(sprite->getPosition().x) % 32));
					
				}
				else
				{
					onGround = false;
					gravityActive = true;
				}
			}
			else if (inLevelMap[5].sloped == 2)
			{
				if (sprite->getPosition().y > ((inLevelMap[5].tilePosition.y - 1) * 32) + (int(sprite->getPosition().x) % 32)) 
				{
					onGround = true;
					gravityActive = false;
					sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + (int(sprite->getPosition().x) % 32));
					
				}
				else
				{
					onGround = false;
					gravityActive = true;
				}

			}
		}
		else
		{
			//if(sprite->getPosition().y)
			if (inLevelMap[6].solid == true || inLevelMap[7].solid == true
				|| inLevelMap[10].solid == true)
			{
				canMoveRight = false;
				std::cout << "This is a normal collision Pos: " << sprite->getPosition().x << ", " << sprite->getPosition().y << std::endl;

				if (sprite->getGlobalBounds().contains(sf::Vector2f(inLevelMap[10].tilePosition.x * 32, sprite->getPosition().y)))
				{
					std::cout << "R Collision\n";

					sprite->setPosition((inLevelMap[10].tilePosition.x - 1) * 32, sprite->getPosition().y);

					//hitbox.setPosition(sprite->getPosition());
				}
			}
			else
			{
				canMoveRight = true;
			}
			if (inLevelMap[0].solid == true || inLevelMap[1].solid == true || inLevelMap[9].solid == true)
			{
				canMoveLeft = false;

				if (sprite->getGlobalBounds().contains(sf::Vector2f(inLevelMap[9].tilePosition.x * 32, sprite->getPosition().y)))
				{
					std::cout << "L Collision\n";
					sprite->setPosition((inLevelMap[9].tilePosition.x + 1) * 32, sprite->getPosition().y);

					//hitbox.setPosition(sprite->getPosition());
				}
			}
			else
			{
				canMoveLeft = true;
			}
			if ((inLevelMap[2].solid == true && inLevelMap[9].solid != true) || inLevelMap[5].solid == true || (inLevelMap[8].solid == true && inLevelMap[10].solid != true))
			{
				gravityActive = false;
				onGround = true;
				/*if (inLevelMap[5].tilePosition.y < sprite->getPosition().y)
				{
					sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + 4);
					//std::cout << ((inLevelMap[5].tilePosition.y) * 32) << ", " << hitboxPoints[5].y << std::endl;
				}*/


				if (sprite->getGlobalBounds().contains(sf::Vector2f(hitbox.getPosition().x, inLevelMap[5].tilePosition.y * 32)))
				{
					sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + 3);
					//6hitbox.setPosition(sprite->getPosition());

				}

			}
			else
			{
				gravityActive = true;
				onGround = false;
			}


			if ((inLevelMap[0].solid == true && inLevelMap[3].solid == true) || (inLevelMap[3].solid == true && inLevelMap[6].solid == true) || inLevelMap[3].solid == true)
			{
				canMoveUp = false;
			}
			else
			{
				canMoveUp = true;
			}
			if (inLevelMap[4].sloped == 1)
			{
				sprite->setPosition(sprite->getPosition().x, (((inLevelMap[5].tilePosition.y - 1) * 32)) - (int(sprite->getPosition().x) % 32));
			}
			if (inLevelMap[4].sloped == 2)
			{
				sprite->setPosition(sprite->getPosition().x, (((inLevelMap[5].tilePosition.y - 1) * 32)) + (int(sprite->getPosition().x) % 32) + 4);
			}
			if (inLevelMap[2].isPlatform == true || inLevelMap[5].isPlatform == true || inLevelMap[8].isPlatform == true)
			{
				std::cout << "Platform\n";


				std::cout << hitboxVel.y << std::endl;
				if (hitboxVel.y >= 0.2)
				{
					/*if (inLevelMap[5].tilePosition.y < sprite->getPosition().y)
					{
						sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + 4);
						//std::cout << ((inLevelMap[5].tilePosition.y) * 32) << ", " << hitboxPoints[5].y << std::endl;
					}*/
				
			
					/*for (int i = 0; i < 10; i++)
					{
						if ((lastPositions[i].x < inLevelMap[5].tilePosition.x * 32 + 32 && lastPositions[i].x > inLevelMap[5].tilePosition.x * 32) && (lastPositions[i].y < inLevelMap[5].tilePosition.y * 32 + 12 && lastPositions[i].y > inLevelMap[5].tilePosition.y * 32))
						{
							sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + 3);
							break;
						}
					}*/

					if (hitboxPoints[5].y < inLevelMap[5].tilePosition.y * 32 + 16 && sprite->getGlobalBounds().contains(sf::Vector2f(sprite->getPosition().x, inLevelMap[5].tilePosition.y * 32)))
					{

						//6hitbox.setPosition(sprite->getPosition());
						gravityActive = false;
						onGround = true;
						sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + 3);
					}

					/*
					if (sprite->getGlobalBounds().contains(sf::Vector2f(hitbox.getPosition().x, inLevelMap[5].tilePosition.y * 32 + 4)) && sprite->getGlobalBounds().contains(sf::Vector2f(hitbox.getPosition().x, inLevelMap[5].tilePosition.y * 32 - 54)))
					{

						sprite->setPosition(sprite->getPosition().x, ((inLevelMap[5].tilePosition.y - 1) * 32) + 2);
						gravityActive = false;
						onGround = true;
						//6hitbox.setPosition(sprite->getPosition());

					}*/

					/*if ((inLevelMap[5].tilePosition.y * 32) - 52 > hitboxPoints[5].y - 64 && (inLevelMap[5].tilePosition.y * 32) + 8 > hitboxPoints[5].y - 4)
					{
						gravityActive = false;
						onGround = true;
						if ((inLevelMap[5].tilePosition.y * 32) - 58 > hitboxPoints[5].y - 62 && (inLevelMap[5].tilePosition.y * 32) + 2 > hitboxPoints[5].y -2)
						{
						//if ( hitboxPoints[5].y < (inLevelMap[5].tilePosition.y*32) - 60)
						//{
							sprite->setPosition(sprite->getPosition().x, (inLevelMap[5].tilePosition.y - 1) * 32 + 2);
						}
					}*/
				}
			}
		}
		hitbox.setPosition(sprite->getPosition());
	}
	void Collider::NewCollision(sf::RectangleShape target, int targetProperty, int collisionType)
	{
		
		if (hitbox.getGlobalBounds().intersects(target.getGlobalBounds()))
		{
			switch (collisionType)
			{
				case 0: //Translation
					std::cout << "Collision detected!\n";
					
					break;
				case 1: //Rigid
					switch(targetProperty)
					{
						case 0: //Normal
							if (hitbox.getPosition().x + hitbox.getOrigin().x >= target.getPosition().x - hitbox.getOrigin().x) //right side of hitbox, left of target
							{
								canMoveRight = false;
								hitbox.setPosition(target.getPosition().x - target.getOrigin().x, hitbox.getPosition().y);
							}
							else
							{
								canMoveRight = true;
							}
							if (hitbox.getPosition().x + hitbox.getOrigin().x >= target.getPosition().x - hitbox.getOrigin().x) //left side of hitbox, right of target
							{
								canMoveLeft = false;
								hitbox.setPosition(target.getPosition().x + target.getOrigin().x, hitbox.getPosition().y);
							}
							else
							{
								canMoveLeft = true;
							}
							if (hitbox.getPosition().x + hitbox.getOrigin().x >= target.getPosition().x - hitbox.getOrigin().x) //top side of hitbox, bottom of target
							{
								canMoveUp = false;
								hitbox.setPosition(hitbox.getPosition().x, target.getPosition().y + target.getOrigin().y);
							}
							else
							{
								canMoveUp = true;
							}
							if (hitbox.getPosition().x + hitbox.getOrigin().x >= target.getPosition().x - hitbox.getOrigin().x) //bottom side of hitbox, top of target
							{
								gravityActive = false;
								onGround = true;
								hitbox.setPosition(hitbox.getPosition().x, target.getPosition().y - target.getOrigin().y);
							}
							else
							{
								gravityActive = true;
								onGround = false;
							}
							break;
						case 1: //Sloped
							break;
						case 2: //Platform
							break;
						case 3: //Empty
							break;
						default:
							break;
					}
					


					break;
				case 2: //Physics
					
					break;
				default:
					
					break;
			}
			
			
		}
		

	}

void Collider::Move()
{
	hitbox.move(movementVelocity.x * deltaTime, movementVelocity.y * deltaTime);
	pSprite->setPosition(hitbox.getPosition());
}
void Collider::ApplyVelocity(sf::Vector2f velocity, float duration)
{
	movementVelocity = velocity;
	std::cout << "Changing velocity: " << movementVelocity.x << std::endl;
}
void Collider::SetSprite(sf::Sprite* p_sprite)
{
	pSprite = p_sprite;
}
Collider::Collider()
{
	hitboxDimensions = sf::Vector2f(40.f, 60.f);
	hitbox.setOrigin(20.f, 30.f);
	hitbox.setFillColor(sf::Color(0,0,0,0));
	hitbox.setOutlineColor(sf::Color::Black);
	hitbox.setSize(hitboxDimensions);
	hitbox.setOutlineThickness(1);

	canMoveLeft = true;
	canMoveRight = true;
	canMove = true;
	gravityActive = false;
	zoneDamage = true;

	movementVelocity = sf::Vector2f(0, 0); 
}
/*Collider::Collider(sf::Vector2f dimensions)
{
		
}*/


