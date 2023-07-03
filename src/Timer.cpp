#include <SFML/Graphics.hpp>

#include "Global.h"
#include "Timer.h"


Timer::Timer()
{


}
Timer::Timer(int time)
{
	totalTime = time;
	countdownActive = true;
	outOfTime = false;
	pauseTime = sf::Time::Zero;


}
Timer::Timer(int time, sf::Vector2f position)
{
	

	totalTime = time;
	countdownActive = true;
	outOfTime = false;
	pauseTime = sf::Time::Zero;
	box.setSize(sf::Vector2f(80, 80));
	box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);
	box.setPosition(position);
	box.setOutlineColor(sf::Color::White);
	box.setFillColor(sf::Color::Black);
	box.setOutlineThickness(5.f);

	timeDisplay.setFont(gameFont);
	timeDisplay.setCharacterSize(2 * box.getSize().x / 3);
	timeDisplay.setOrigin(timeDisplay.getCharacterSize() / 2, timeDisplay.getCharacterSize() / 2);
	timeDisplay.setPosition(box.getPosition().x + 12, box.getPosition().y - 4);


}
bool Timer::TimeOut()
{
	return outOfTime;
}
void Timer::Update()
{
	
	if (countdownActive == true)
	{
		
		if (totalTime - clock.getElapsedTime().asSeconds() - pauseTime.asSeconds() > 0)
		{
			
			timeLeft = totalTime - clock.getElapsedTime().asSeconds() - pauseTime.asSeconds();
			timeDisplay.setString(std::to_string(timeLeft));
			outOfTime = false;
		}
		else
		{
			timeDisplay.setString("0");
			countdownActive = false;
			outOfTime = true;
		}
	}
	
}
void Timer::StartTimer()
{
	clock.restart();
	countdownActive = true;
	
}
void Timer::ResetTimer()
{
	timeLeft = totalTime;
	pauseTime = sf::Time::Zero;
	countdownActive = false;
	outOfTime = false;
}
void Timer::Pause()
{
	pauseTime = clock.getElapsedTime();
	
	countdownActive = false;
}
void Timer::Draw(sf::RenderWindow& window)
{
	window.draw(box);
	window.draw(timeDisplay);
	

}
void Timer::SetPosition(sf::Vector2f position)
{
	box.setPosition(position);
	timeDisplay.setPosition(box.getPosition().x + 12, box.getPosition().y - 4);
}