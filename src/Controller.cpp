#include <SFML/Graphics.hpp>

#include "Controller.h"

Controller::Controller()
{
	controls[0] = sf::Keyboard::W;
	controls[1] = sf::Keyboard::A;
	controls[2] = sf::Keyboard::S;
	controls[3] = sf::Keyboard::D;
	controls[4] = sf::Keyboard::E;

	playerSprite = NULL;
}
Controller::~Controller()
{
	delete playerSprite;
}
Controller::Controller(sf::Sprite* pSourceSprite, int controlSet)
{
	playerSprite = pSourceSprite;
	switch (controlSet)
	{
	case 1:
		controls[0] = sf::Keyboard::W;
		controls[1] = sf::Keyboard::A;
		controls[2] = sf::Keyboard::S;
		controls[3] = sf::Keyboard::D;
		controls[4] = sf::Keyboard::E;
		break;
	case 2:
		controls[0] = sf::Keyboard::Up;
		controls[1] = sf::Keyboard::Left;
		controls[2] = sf::Keyboard::Down;
		controls[3] = sf::Keyboard::Right;
		controls[4] = sf::Keyboard::RControl;
		break;
	case 3:
		controls[0] = sf::Keyboard::I;
		controls[1] = sf::Keyboard::J;
		controls[2] = sf::Keyboard::K;
		controls[3] = sf::Keyboard::L;
		controls[4] = sf::Keyboard::O;
		break;
	case 4:
		controls[0] = sf::Keyboard::Numpad8;
		controls[1] = sf::Keyboard::Numpad4;
		controls[2] = sf::Keyboard::Numpad5;
		controls[3] = sf::Keyboard::Numpad6;
		controls[4] = sf::Keyboard::Numpad9;
		break;

	}

}

void Controller::Move(sf::Vector2f velocity)
{
	//playerSprite->move(velocity);
}
bool Controller::UpKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(controls[0]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Controller::DownKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(controls[2]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Controller::LeftKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(controls[1]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Controller::RightKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(controls[3]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Controller::UseKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(controls[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}