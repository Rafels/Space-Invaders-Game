#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdexcept>

class Winner
{
public:
	Winner();
	sf::Sprite & getSprite();
	void setLocation(float, float);
	void draw(sf::RenderWindow &win);
private:
	sf::Sprite sprite;
	sf::Texture texture;
};
