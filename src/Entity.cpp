#include <SFML/Graphics.hpp>

#include "Global.h"
#include "Collider.h"
#include "Entity.h"

Entity::Entity()
{
	
	gravitySpeed = 0.9f; //0.3 (0.6
	gravitySpeed = ((1 * 0.02025) / (0.28 * 0.28)) * 5; //((0.8 * 0.02025) / (0.35 * 0.35)) * 5;
	
	totalVelocities = 5;
	for (int i = 0; i < totalVelocities; i++)
	{
		velocities[i] = sf::Vector2f(0, 0);
	}
	maxGravitySpeed = 0.8f;
	movementSpeed = 0.45f; //0.45
	maxSpeed = 0.7; //0.7
	texture.loadFromFile("index/assets/sprites/Player.png");
	sprite.setTexture(texture);
	sprite.setPosition(100, 100);
	velocity = sf::Vector2f(0, 0);
	externalVelocity = sf::Vector2f(0, 0);

}
/*void Entity::Update(float dt/*, int* levelArray)
{
	Gravity(dt);
}*/
void Entity::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	//window.draw(collider.hitbox);
	
}
void Entity::ApplyForces(float dt)
{
	sprite.move(velocity.x * dt, velocity.y * dt);
}
void Entity::SumVelocity()
{
	sf::Vector2f forces = sf::Vector2f(0, 0);
	for (int i = 0; i < 5; i++)
	{
		forces += velocities[i];
	}
	velocity = forces;
	
}

/*void Entity::Gravity(float dt)
{
	/*if(gravityActive == true)
	{
		canMoveLeft = true;
		canMoveRight = true;
		canJump = false;
		sprite.move(0, gravitySpeed * dt);
		velocity.y = 1;
	}
}*/
sf::Vector2f Entity::GetPosition()
{
	return sprite.getPosition();
}
void Entity::SetPosition(sf::Vector2f position)
{

	sprite.setPosition(position);
}
	
void Entity::Gravity()
{
	if (collider.gravityActive == true)
	{
		velocities[1].y = maxGravitySpeed;
	}

}