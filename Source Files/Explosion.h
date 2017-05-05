#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Explosion
{
public:
	Explosion();
	~Explosion();
	void animate(sf::RenderWindow &win, int i, int j);
	bool getIsAlive();
	void spawn();
	void kill();
	void setPosition(sf::Vector2f);
	sf::Sprite& getSprite();
	sf::Texture& getTexture();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	bool isAlive;

};