#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"
#include "GUI.h"

void GUI::Draw(sf::RenderWindow &window)
{
	window.setView(sf::View(sf::FloatRect(2720.f, 3280.f, 1280.f, 720.f)));
	window.draw(*sprite);
	//window.draw(*text);

}
void GUI::Update(float dt)
{

}


GUI::GUI()
{


}
GUI::~GUI()
{
	delete text;
	delete font;
	delete sprite;
	delete texture;
	
}
GUI::GUI(std::string filepath, int frames)
{
	texture->loadFromFile(filepath);
	sprite->setTexture(*texture);
	font->loadFromFile("index/assets/fonts/ka1.ttf");
	text->setFont(*font);
	nFrames = frames;
	frameSize = sf::Vector2i(texture->getSize().x / frames, texture->getSize().y);
	spriteSource.left = 0;
	spriteSource.top = 0;
	spriteSource.width = frameSize.x;
	spriteSource.height = frameSize.y;
	sprite->setTextureRect(spriteSource);
	sprite->setScale(0.4f, 0.4f);

	drawText = false;
};
void GUI::NextFrame()
{

	if (spriteSource.left < texture->getSize().x - frameSize.x)
	{
		spriteSource.left += frameSize.x;

	}
	else
	{
		spriteSource.left = 0;
	}
	sprite->setTextureRect(spriteSource);

}
void GUI::GotoFrame(int frameNum)
{
	if (frameNum - 1 < nFrames && nFrames - frameNum != 7)
	{
		spriteSource.left = frameSize.x * (nFrames - frameNum);
	}
	else
	{
		//std::cout << "Error: frameNum > framerate\n";//I felt like implementing this one day, I dont know why 
													   //then another day helped me fix a bug... Imagine that.
	}
	sprite->setTextureRect(spriteSource);

}
void GUI::BackFrame()
{
	if (spriteSource.left != 0)
	{
		spriteSource.left -= frameSize.x;

	}
	else
	{
		spriteSource.left = texture->getSize().x - frameSize.x;
	}
	sprite->setTextureRect(spriteSource);

}

