#ifndef PLAYERGUI_H_INCLUDED
#define PLAYERGUI_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "GUI.h"

class PlayerGUI : public GUI
{
	protected:
		sf::Vector2f spritePositions[3];
		sf::Vector2f offset;
	public:
		PlayerGUI();
		PlayerGUI(int playerNum);
		void Update(sf::Texture* texture1, sf::Texture* texture2, int info, int type);
		void Draw(sf::RenderWindow& window);
};


#endif