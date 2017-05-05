#include "Asteroid.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "Aliens.h"

Asteroid::Asteroid()
{

}
Asteroid::Asteroid(sf::Vector2f pos, std::string path)
	:Entity(pos, sf::Vector2f(0,0), path)
{
	getSprite().setScale(0.1,0.1);
}
void Asteroid::collide(Entity* e)
{
	e->collide(this);
}
void Asteroid::collide(Bullet* e)
{
	/*
	if (e->getIsAlive == false)
		return;
	*/
	if (getIsAlive() == false)
		return;
	kill();
	e->kill();
}
void Asteroid::collide(Asteroid* e)
{

}
void Asteroid::collide(Spaceship* e)
{

}
void Asteroid::collide(Aliens* e)
{
	/*
	if (e->getIsAlive == false)
		return;
	*/
	if (getIsAlive() == false)
		return;
	kill();
}
Asteroid::~Asteroid()
{

}