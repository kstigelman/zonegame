
#include <SFML/Graphics.hpp>
#include "GUI.h"
#include "PlayerGUI.h"

PlayerGUI::PlayerGUI()
{
	text = nullptr;
}
PlayerGUI::PlayerGUI(int playerNum)
{
	text = new sf::Text;
	text->setFont(gameFont);
	text->setCharacterSize(18);
	text->setFillColor(sf::Color::Black);
	sprite = new sf::Sprite[3];
	sprite->setScale(0.6f, 0.6f);
	texture = new sf::Texture[3];
	texture[0].loadFromFile("index/assets/sprites/PlayerGUI.png");
	
	sprite[0].setPosition(2900, 3875);
	spritePositions[0] = sf::Vector2f(2900, 3885);
	spritePositions[1] = sf::Vector2f(2940, 3940);
	spritePositions[2] = sf::Vector2f(3002, 3968);
	offset = sf::Vector2f(200, 0);

	switch (playerNum)
	{
		case 1:
			sprite[0].setTextureRect(sf::IntRect(0, 0, 240, 192));
			
			break;
		case 2:
			
			sprite[0].setTextureRect(sf::IntRect(240, 0, 240, 192));
			
			break;
		case 3:
			sprite[0].setTextureRect(sf::IntRect(480, 0, 240, 192));
			break;
		case 4:
			sprite[0].setTextureRect(sf::IntRect(720, 0, 240, 192));
			break;
	}
	offset = sf::Vector2f((200 * (playerNum-1)), 0);
	for (int i = 0; i < 3; i++)
	{
		spritePositions[i] = spritePositions[i] + offset;
		sprite[i].setPosition(spritePositions[i]);
	}
	sprite[0].setTexture(texture[0]);

	text->setPosition(sprite[1].getPosition().x + 8, sprite[1].getPosition().y - 22);
}
void PlayerGUI::Update(sf::Texture* texture1, sf::Texture* texture2, int info, int type)
{
	texture[1] = *texture1;
	texture[2] = *texture2;

	sprite[1].setTexture(*texture1);
	sprite[1].setOrigin(texture1->getSize().x / 2, texture1->getSize().y / 2);
	sprite[1].setScale(1.25f, 1.25f);

	sprite[2].setTexture(*texture2);
	sprite[2].setOrigin(texture2->getSize().x / 2, texture2->getSize().y / 2);
	sprite[2].setScale(0.65f, 0.65f);

	text->setString(std::to_string(info));
	if (type == 0)
	{
		drawText = true;
		text->setPosition(sprite[1].getPosition().x + 3, sprite[1].getPosition().y - 22);
		text->setCharacterSize(18);

	}
	else
	{
		//drawText = false;

		text->setPosition(sprite[1].getPosition().x + 65, sprite[1].getPosition().y + 16);
		text->setCharacterSize(12);
	}
	//if(sprite[1].getTexture())
	
}

void PlayerGUI::Draw(sf::RenderWindow& window)
{
	window.setView(sf::View(sf::FloatRect(2720.f, 3280.f, 1280.f, 720.f)));
	for (int i = 0; i < 3; i++)
	{
		window.draw(sprite[i]);
	}
	if (drawText == true)
	{
		window.draw(*text);
	}
}