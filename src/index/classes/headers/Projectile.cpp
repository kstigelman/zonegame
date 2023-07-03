#include <SFML/Graphics.hpp>
#include "Projectile.h"

Projectile::Projectile()
{
	texture.loadFromFile("index/assets/sprites/Projectile.png");
	sprite.setTexture(texture);
	isActive = false;
	velocity = sf::Vector2f(0, 0);
	firstFire = false;

}
void Projectile::Draw(sf::RenderWindow &window)
{
	if (isActive == true)
	{
		window.draw(sprite);
	}
}
void Projectile::Update(float dt)
{
	if (isActive == true)
	{
		if (firstFire == false)
		{
			fireClock.restart();
			firstFire = true;
		}
		if (firstFire == true)
		{
			velocity.x = (4 / (1 + std::exp(-5 * (fireClock.getElapsedTime().asSeconds() - 0.75)))) * dt;
			sprite.move(velocity);
		}

	}
}