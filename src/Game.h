#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "GameEffect.h"
#include "Global.h"
#include "Level.h"
#include "Camera.h"
#include "Player.h"
#include "Zone.h"

enum GameState = { start, title, options, play, exit };

class Game
{
	private:
			float timePassed;
			sf::Texture titleTexture;
			sf::RectangleShape title;
			sf::RenderWindow window;
			float WIDTH;
			float HEIGHT;

			GameState state;

			sf::Clock clock;
			bool paused;

			float deltaTime;

			char camDirection;
			int playersLeft;
			bool playersOut[4];
			sf::View view;
			sf::View backgroundView;
			sf::View titleView;
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;
			//Player player;
			Level level;
			Camera camera;
			GameEffect gameEffect;
			std::vector<Item> item;
			Player* player;
			Player* p2;
			Player* players[4];
			Zone* zone;
			//Collider* p_collider;
			
			bool testbool;

		public:
			
			void Run();
			void EventManager();
			void Update();

			void Render();
			void GameStateHandler();
			Game();
			~Game();
};

#endif
