#include "Asteroid.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "Aliens.h"

Aliens::Aliens(sf::Vector2f pos, sf::Vector2f spd, std::string path)
	:Entity(pos,spd,path)
{
	getSprite().setScale(sf::Vector2f(0.25, 0.25));
}
void Aliens::setLives(int liv)
{
	lives = liv;
}
int Aliens::getLives()
{
	return lives;
}
void Aliens::collide(Entity* e)
{
	
}
void Aliens::collide(Bullet* e)
{
	/*
	if (e->getIsAlive == false)
		return;
	*/
	if (getIsAlive() == false)
		return;
	lives--;
	if(lives <= 0)
    {
		kill();
	}
	e->kill();
}
void Aliens::collide(Asteroid* e)
{

}
void Aliens::collide(Spaceship* e)
{
	/*
	if (e->getIsAlive == false)
		return;
	*/
	if (getIsAlive() == false)
		return;
	e->kill();
}
void Aliens::collide(Aliens* e)
{

}
Aliens::~Aliens()
{

}