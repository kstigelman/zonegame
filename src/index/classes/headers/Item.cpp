#include <SFML/Graphics.hpp>
#include <iostream>


#include "Global.h"

#include "Collider.h"
//#include "Player.h"
#include "Item.h"

Item::Item()
{
	canSwitchItem = true;
	currentlyUsed = false;
	isActive = true;
	inUse = false;
	useItemKey = sf::Keyboard::E;
	
	type = 0;
	l_Sprites = NULL;
}
Item::~Item()
{
	delete l_Sprites;
}
Item::Item(std::string texturePath)
{
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
	type = 0;

	l_Sprites = NULL;
}
void Item::Draw(sf::RenderWindow &window)
{
	if (isActive == true && currentlyUsed == true)
	{
		window.draw(sprite);
	}
}
void Item::Update(float dt, sf::Sprite *pSprite, Collider* collider, std::vector<sf::Sprite>* sprites)
{
	
	if (isActive == true)
	{
		if (sf::Keyboard::isKeyPressed(useItemKey))
		{
			std::cout << "Executed\n";
			
			Use();
		}
	}
}
void Item::Update(float dt, sf::Sprite* pSprite, std::vector<sf::Sprite>* sprites)
{
	if (isActive == true)
	{
		if (sf::Keyboard::isKeyPressed(useItemKey))
		{
			std::cout << "Executed\n";

			Use();
		}
	}


}
void Item::Use()
{
	
}
void Item::Extra()
{

}
sf::Texture* Item::GetTexture()
{
	return &texture;
}
void Item::SendGlobalSprites(Collider* m_Sprites)
{
	l_Sprites = m_Sprites;
}