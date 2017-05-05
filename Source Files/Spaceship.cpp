#include "Asteroid.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "Aliens.h"

Spaceship::Spaceship(sf::Vector2f pos, sf::Vector2f spd, std::string path):
	Entity(pos,spd,path)
{
	getSprite().setScale(0.075, 0.075);
}
void Spaceship::setLives(int liv) 
{
	lives = liv;
}
int Spaceship::getLives()
{
	return lives;
}
void Spaceship::collide(Entity* e)
{

}
void Spaceship::collide(Bullet* e)
{
	/*if (e->getIsAlive == false)
		return;
	*/
	if (getIsAlive() == false)
		return;
	lives--;
	if (lives <= 0)
	{
		kill();
	}
	e->kill();
}
void Spaceship::collide(Asteroid* e)
{

}
void Spaceship::collide(Spaceship* e)
{

}
void Spaceship::collide(Aliens* e)
{
	/*
	if (e->getIsAlive == false)
		return;
	*/
	if (getIsAlive() == false)
		return;
	kill();
}

Spaceship::~Spaceship()
{

}