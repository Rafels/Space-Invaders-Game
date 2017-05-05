#include "Loser.h"

Loser::Loser()
{
	if (!texture.loadFromFile("YouLose.png"))
		throw std::invalid_argument("Lose screen not loaded");

	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.8, 0.8));
	sprite.setPosition(100, 100);
}

sf::Sprite &Loser::getSprite()
{
	return sprite;
}

void Loser::setLocation(float xpos, float ypos)
{
	sprite.setPosition(xpos, ypos);
}

void Loser::draw(sf::RenderWindow &win)
{
	sprite.setTexture(texture);
	win.draw(sprite);
}