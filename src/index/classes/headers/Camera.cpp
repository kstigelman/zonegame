#include <SFML/Graphics.hpp>
#include <iostream>

#include "Global.h"
#include "Camera.h"


		Camera::Camera()
		{
			scrollSpeed = 0.03f; // 0.065 //0.03 range or 0.03 to 0.065 are good speeds
			cam.setSize(1280, 720);
			cam.setCenter(640, 644);
			
			cam.zoom(1.5); //1.5
			cam.move(400, 0);
			active = true;
			scrollDirection = 'R';
			
		}
		void Camera::Scroll(float dt)
		{
			//position.x += scrollSpeed * dt
			
			cam.move(scrollSpeed * dt, 0);
			//Add functionality for changing direction, and two axis scoll at once

		}
		sf::Vector2f Camera::GetCenter()
		{
			return cam.getCenter();
		}
		void Camera::Update(float dt,  char direction)
		{
			
			scrollDirection = direction;
			cameraBounds[0] = sf::Vector2f(cam.getCenter().x - cam.getSize().x / 2, cam.getCenter().y - (cam.getSize().y / 2));
			cameraBounds[1] = sf::Vector2f(cam.getCenter().x + (cam.getSize().x / 2), cam.getCenter().y + (cam.getSize().y / 2));
			Scroll(dt);
			
			
		}
		void Camera::Move(float dt) //Method for manual camera scroll
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				cam.move(0, -scrollSpeed * dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				cam.move(0, scrollSpeed * dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				cam.move(-scrollSpeed * dt, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				cam.move(scrollSpeed * dt, 0);
			}
				
		}
		void Camera::ChangeScrollSpeed(float newSpeed)
		{
			scrollSpeed = newSpeed;
		}