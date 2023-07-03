#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Global.h"


//sf::Vector2f cameraBounds[2];


class Camera
{
	private:
		
		sf::Vector2f position;
		bool active;
	public:
		sf::View cam;
		

		float scrollSpeed;
		char scrollDirection;
		Camera();
		void Scroll(float dt);
		void Update(float dt,char direction);
		void Move(float dt);
		void ChangeScrollSpeed(float newSpeed);
		sf::Vector2f GetCenter();

};
#endif