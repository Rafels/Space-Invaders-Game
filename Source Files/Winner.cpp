#include "Winner.h"

Winner::Winner()
{
	if (!texture.loadFromFile("YouWin.png"))
		throw std::invalid_argument("Game Over screen not loaded!");

	sprite.scale(0.8, 0.8);
	sprite.setPosition(100, 100);
}

sf::Sprite &Winner::getSprite()
{
	return sprite;
}

void Winner::setLocation(float xpos, float ypos)
{
	sprite.setPosition(xpos, ypos);
}

void Winner::draw(sf::RenderWindow &win)
{
	sprite.setTexture(texture);
	win.draw(sprite);
}