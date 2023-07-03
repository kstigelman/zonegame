#include <SFML/Graphics.hpp>

#include "Global.h"
#include "Player.h"
#include "Zone.h"

Zone::Zone(int WIDTH, int HEIGHT)
{
	movementSpeed = 0.006f; //0.005 //0.006 is default
	texture.loadFromFile("Zone.png");
	zone[0].setSize(sf::Vector2f(WIDTH, HEIGHT * 2));
	zone[1].setSize(sf::Vector2f(WIDTH, HEIGHT * 2));

	zone[0].setPosition(0 - WIDTH * 1.25, (-HEIGHT / 2) + 144);
	zone[1].setPosition(WIDTH * 1.25, (-HEIGHT / 2) + 144);
	
	zone[0].setPosition(400 - WIDTH * 1.25, (-HEIGHT / 2) + 144); //Change 400 to spawn center
	zone[1].setPosition(400 + WIDTH * 1.25, (-HEIGHT / 2) + 144);

	zone[0].setFillColor(sf::Color(0, 128, 255, 150));
	zone[1].setFillColor(sf::Color(0, 128, 255, 150));
}
Zone::~Zone()
{

}
void Zone::MoveIn(float dt, float scrollSpeed)
{
	if(distanceBetweenZones > 0)
	{
		zone[0].move((scrollSpeed + movementSpeed) * dt, 0);
		zone[1].move((scrollSpeed - movementSpeed) * dt, 0);
	}
}
void Zone::Update(float dt, float scrollSpeed)
{
	
	distanceBetweenZones = zone[1].getPosition().x - zone[0].getPosition().x;
	MoveIn(dt, scrollSpeed);
	
}
void Zone::Render(sf::RenderWindow &window)
{
		window.draw(zone[0]);
		window.draw(zone[1]);
}
void Zone::OnPlayerEnter(Player* player)
{
	for (int i = 0; i < 2; i++)
	{
		if (zone[i].getGlobalBounds().contains(player->sprite.getPosition()))
		{
			if (player->collider.zoneDamage == true)
			{
				player->setActive(false);
				player->Remove();

			}
		}
	}

}