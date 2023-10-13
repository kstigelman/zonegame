#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <cstring>

#include "Global.h"

class Timer
{
protected:
	sf::Text timeDisplay;
	sf::Clock clock;
	int timeLeft;
	
	bool outOfTime;
	int totalTime;
	bool countdownActive;
	sf::Time pauseTime;
public:
	sf::RectangleShape box;
	Timer();
	Timer(int time);
	Timer(int time, sf::Vector2f position);
	void Update();
	void Draw(sf::RenderWindow& window);
	void StartTimer();
	void ResetTimer();
	void Pause();
	void SetPosition(sf::Vector2f position);
	bool TimeOut();
};

#endif