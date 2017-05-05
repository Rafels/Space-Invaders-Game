#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdexcept>

class Loser
{
public:
	Loser();
	sf::Sprite & getSprite();
	void setLocation(float, float);
	void draw(sf::RenderWindow &win);
private:
	sf::Sprite sprite;
	sf::Texture texture;
};

