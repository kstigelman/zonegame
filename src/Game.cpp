#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameEffect.h"
#include "Global.h"
#include "Level.h"
#include "Camera.h"
#include "Player.h"
#include "Zone.h"
#include "Game.h"

		void Game::Run()
		{
			
			while(window.isOpen())
			{
				sf::Time time;
				time = clock.getElapsedTime();
				deltaTime = time.asMilliseconds();

			
				clock.restart().asSeconds();

				GameStateHandler();

				EventManager();
				if(!paused)
				{
					Update();
				}
				Render();
			}
		}

		void Game::EventManager()
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					
					window.close();
					//delete players;
				}

			}
			
		}
		Game::~Game()
		{
			delete zone;
			delete[] players;
			delete player;
			delete p2;

			
		}
		void Game::Update() {


			if (gameState == 0) //Title Screen
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					gameState = 1; //Start game
					
				}
			}
			if (gameState == 1) //Game loop
			{
				
				gameEffect.Update(); 
				zone->Update(deltaTime, camera.scrollSpeed);
				camera.Update(deltaTime, camDirection);


				for (int i = 0; i < 4; i++) //Update players, check if players have entered zone
				{
					//players[i]->item->SendGlobalSprites(p_collider); //players[i]->collider.ApplyVelocity(p_collider[i].movementVelocity, 0);
					
					players[i]->Update(deltaTime, &level);
					zone->OnPlayerEnter(players[i]); //Don't change to *players, it causes a crash.
					

					if (players[i]->sprite.getPosition().x < 100)
					{

						players[i]->collider.canMoveLeft = false;

					}

				}

				//Determine which game effect should be applied - some only happen once
				if (gameEffect.effectType == 1 && gameEffect.updateGameEffect == true)
				{

					camera.ChangeScrollSpeed(-camera.scrollSpeed);
					std::cout << "Changed Direction!" << std::endl;
					gameEffect.updateGameEffect = false;

				}
				if (gameEffect.effectType == 0 && gameEffect.updateGameEffect == true)
				{

					if (camera.scrollSpeed < 0)
					{

						camera.ChangeScrollSpeed(-0.065f); //0.085

					}
					if (camera.scrollSpeed > 0)
					{

						camera.ChangeScrollSpeed(0.065f); //0.085

					}

					std::cout << "Changed Speed!" << std::endl;
					gameEffect.updateGameEffect = false;
				}
			}
		}
		void Game::Render()
		{
			window.clear();

			if (gameState == 0) //Render title screen if in title screen state
			{
				window.setView(titleView);
				window.draw(title);
			}
			if (gameState == 1) //Render game
			{
				window.setView(backgroundView);
				window.draw(backgroundSprite);
				window.setView(camera.cam);

				level.Draw(window);

				
				for (int i = 0; i < 4; i++)
				{

					players[i]->Draw(window); 

				}
				
				
				zone->Render(window);

				
				for (int i = 0; i < 4; i++)
				{

					players[i]->playerGUI->Draw(window);

				}

				gameEffect.Draw(window);
			}

			window.display();

		}
		void Game::GameStateHandler()
		{
		}
		Game::Game()
		{
			testbool = true;

			WIDTH = 1280;
			HEIGHT = 720;
			zone = new Zone(WIDTH, HEIGHT);
			window.create(sf::VideoMode(WIDTH, HEIGHT), "WAVE GAME");
			window.setFramerateLimit(144);
			playerCount = 4;
			gameState = 0;
			std::cout << "================================\n\n";
			titleTexture.loadFromFile("index/assets/sprites/title.png");
			title = sf::RectangleShape(sf::Vector2f(1280, 720));
			title.setTexture(&titleTexture);
			title.setOrigin(640, 360);
			title.setPosition(1920, 8000);
			titleView.setCenter(1920, 8000);
			titleView.setSize(1280, 720);
			backgroundView.setCenter(1920, 5000);
			backgroundView.setSize(1920, 1080);
			backgroundTexture.loadFromFile("index/assets/sprites/Background.png");
			backgroundSprite.setTexture(backgroundTexture);
			backgroundSprite.setOrigin(sf::Vector2f(backgroundTexture.getSize().x / 2, backgroundTexture.getSize().y / 2));
			backgroundSprite.setPosition(1920, 5000);

			gameFont.loadFromFile("index/assets/fonts/carbonbl.ttf");
			camDirection = 'R';


			//4 players - not spawning
			for (int i = 0; i < 4; i++)
			{
				players[i] = new Player(i + 1, sf::Vector2f(40, 60));
				players[i]->sprite.setTextureRect(sf::IntRect(12, 0, 40, 60));
			}

			//This makes only 1 spawn - working
			player = new Player(1, sf::Vector2f(40, 60));
			player->sprite.setTextureRect(sf::IntRect(12, 0, 40, 60));



			//p2 = new Player(2, sf::Vector2f(48, 80));
			//p2->sprite.setTextureRect(sf::IntRect(12, 0, 40, 60));
			paused = false;

			playersLeft = 4;
			for (int i = 0; i < 4; i++)
			{
				playersOut[i] = false;
			}
			/*
			p_collider = new Collider[4];

			for (int i = 0; i < 4; i++)
			{
				p_collider[i] = players[i]->collider;
			}*/
			
		}

