#ifndef FIREWORK_H_INCLUDED
#define FIREWORK_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"
#include "Item.h"

class Firework : public Item
{
	protected:

	public:
		Firework();
		Firework(std::string texturePath);
		void Launch();



};

#endif
