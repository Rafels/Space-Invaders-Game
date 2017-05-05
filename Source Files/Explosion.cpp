#include "Explosion.h"

Explosion::Explosion()
{
	texture.loadFromFile("explosion.png");
	sprite.setTexture(texture);
}
void Explosion::animate(sf::RenderWindow &win, int i, int j)
{
	sprite.setTextureRect(sf::IntRect(j*64,i*64,64,64));
	win.draw(sprite);
}
bool Explosion::getIsAlive()
{
	return isAlive;
}
void Explosion::spawn()
{
	isAlive = true;
}
void Explosion::kill()
{
	isAlive = false;
}
void Explosion::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}
sf::Sprite& Explosion::getSprite()
{
	return sprite;
}
sf::Texture& Explosion::getTexture()
{
	return texture;
}

Explosion::~Explosion()
{

}