#include <SFML/Graphics.hpp>
#include <iostream>

#include "Balloon.h"
#include "Entity.h"
#include "Global.h"
#include "Item.h"

Balloon::Balloon()
{
	useCooldown = 5.f;
	inUse = false;

	texture.loadFromFile("index/assets/sprites/Balloon.png");
	sprite.setTexture(texture);

}

/*void Balloon::Update(float dt, Entity *pEntity,  std::vector<sf::Sprite>* sprites)
{



}*/