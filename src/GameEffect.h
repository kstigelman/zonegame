#ifndef GAMEEFFECT_H_INCLUDED
#define GAMEEFFECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "Global.h"
class GameEffect
{
	protected:
		sf::Clock effectTimer;
		
		sf::Text text;
		float initialTime;
		float timeBetweenEffects;
		bool doesEffect;
		bool firstUpdate;
		int roundCounter;
		int effectPool[3];
	public:
		bool updateGameEffect;
		int effectType; //0 - Direction change, 1 - gravity change, 2 - Speed change 
		GameEffect();
		GameEffect(int gamemode);
		void Update();
		void Draw(sf::RenderWindow &window);
		void EffectManager();
		
};

#endif
