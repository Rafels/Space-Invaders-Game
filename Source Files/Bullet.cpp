#include "Asteroid.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "Aliens.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f spd, std::string path)
	:Entity(pos,spd,path)
{
	getSprite().setScale(sf::Vector2f(0.1, 0.1));
}

void Bullet::collide(Entity* e)
{
	e->collide(this);
}
void Bullet::collide(Bullet* e)
{

}
void Bullet::collide(Asteroid* e)
{

}
void Bullet::collide(Spaceship* e)
{

}
void Bullet::collide(Aliens* e)
{

}

Bullet::~Bullet()
{

}
void Bullet::setHostile() 
{
	hostile = true;
}
void Bullet::setPassive() 
{
	hostile = false;
}
bool Bullet::isHostile() 
{
	return hostile;
}