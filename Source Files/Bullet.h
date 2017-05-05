#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	Bullet(sf::Vector2f pos, sf::Vector2f spd, std::string path);
	void collide(Entity* e) override;
	void collide(Bullet* e) override;
	void collide(Asteroid* e) override;
	void collide(Spaceship* e) override;
	void collide(Aliens* e) override;
	~Bullet();
	void setHostile();
	void setPassive();
	bool isHostile();

private:
	bool hostile = false;

};