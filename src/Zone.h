#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Player.h"

class Zone
{
	private:
		sf::Texture texture;
		float distanceBetweenZones;
		float movementSpeed;
	public:
		sf::RectangleShape zone[2];
		Zone(int WIDTH, int HEIGHT);
		~Zone();
		
		void MoveIn( float dt, float scrollSpeed);
		void Update(float dt, float scrollSpeed);
		void Render(sf::RenderWindow &window);
		void OnPlayerEnter(Player* player);
};

#endif
