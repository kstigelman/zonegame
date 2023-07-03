#ifndef HITBOX_H_INCLUDED
#define HITBOX_H_INCLUDED


#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"


class Hitbox
{
	protected:
		int canMove[4]; //UP-RIGHT-DOWN-LEFT
		sf::RectangleShape hitbox;
		sf::Vector2f hitboxDimensions;
	public:
		

};
#endif