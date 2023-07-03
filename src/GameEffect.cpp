#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "Global.h"
#include "GameEffect.h"


GameEffect::GameEffect()
{
	initialTime = 10;
	doesEffect = false;
	firstUpdate = false;
	text.setFont(gameFont);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(2750, 3290);
	timeBetweenEffects = 60;
	updateGameEffect = false;
	roundCounter = 0;

	for (int i = 0; i < 3; i++)
	{
		effectPool[i] = i;
	}

}
GameEffect::GameEffect(int gamemode)
{
	roundCounter = 0;
	if (gamemode == 0)
	{
		timeBetweenEffects = 60;
	}
	else
	{
		timeBetweenEffects = 30;
	}
}
void GameEffect::Update()
{
	if (firstUpdate == false)
	{
		firstUpdate = true;
		effectTimer.restart();
	}
	if (effectTimer.getElapsedTime().asSeconds() > initialTime && doesEffect == false && firstUpdate == true)
	{
		doesEffect = true;
		effectTimer.restart();
	}
	if (doesEffect == true)
	{
		text.setString("Time till next event: " + std::to_string(int(60 - floor(effectTimer.getElapsedTime().asSeconds()))));
		if (effectTimer.getElapsedTime().asSeconds() >= timeBetweenEffects)
		{
			effectTimer.restart();
			roundCounter++;
			EffectManager();
			updateGameEffect = true;
		}
	}
}
void GameEffect::Draw(sf::RenderWindow& window)
{
	window.draw(text);

}
void GameEffect::EffectManager()
{
	srand(time(0));
	int randomNum = rand() % 9;
	/*switch (roundCounter)
	{

		case 1:
			randomNum = rand() % 9;
			break;
		case 2:
			randomNum = rand() % 6;
			break;
		case 3:
			randomNum = rand() % 3;
			break;
		default:
			randomNum = rand() % 9;
			break;
	}*/

	if (roundCounter == 1)
	{
		if (randomNum >= 5)
		{
			effectType = effectPool[0];
			effectPool[0] = 1;
		}
		else if (randomNum >= 0)
		{
			effectType = effectPool[2];
			effectPool[2] = 1;
		}
		
	}
	else if (roundCounter > 1)
	{
		if (randomNum >= 6)
		{
			effectType = effectPool[0];

			effectPool[0] = 1;
		}
		else if (randomNum >= 3)
		{
			effectType = effectPool[1];
		}
		else if (randomNum >= 0)
		{
			effectType = effectPool[2];
			effectPool[2] = 1;
		}
	}
	
}
