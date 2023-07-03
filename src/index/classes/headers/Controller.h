#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <SFML/Graphics.hpp>


class Controller // Eventuall include Animator in this class
{
	protected:
		sf::Sprite* playerSprite;
		sf::Keyboard::Key controls[5];
	public:
		Controller();
		Controller(sf::Sprite* pSourceSprite, int controlSet);
		~Controller();
		void Move(sf::Vector2f velocity);
		bool UpKeyPressed();
		bool DownKeyPressed();
		bool LeftKeyPressed();
		bool RightKeyPressed();
		bool SwitchKeyPressed();
		bool UseKeyPressed();
};
#endif