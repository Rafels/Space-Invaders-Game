#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.h"

class Spaceship : public Entity
{
public:
	Spaceship(sf::Vector2f pos, sf::Vector2f spd, std::string path);
	void setLives(int);
	int getLives();
	void collide(Entity* e) override;
	void collide(Bullet* e) override;
	void collide(Asteroid* e) override;
	void collide(Spaceship* e) override;
	void collide(Aliens* e) override;
	~Spaceship();
private:
	int lives = 3;
	int score;
};

