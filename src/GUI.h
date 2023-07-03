#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"
class GUI
{
	protected:
		sf::Font* font;
		sf::Text* text;

		sf::Texture* texture;
		sf::Sprite* sprite;

		sf::IntRect spriteSource;
		int framerate;
		int nFrames;
		sf::Vector2i frameSize;
		bool drawText;
	public:
		GUI();
		GUI(std::string filepath, int frames);
		~GUI();
		virtual void Draw(sf::RenderWindow &window);
		virtual void Update(float dt);
		void NextFrame();
		void GotoFrame(int frameNum);
		void BackFrame();
};

	
#endif
