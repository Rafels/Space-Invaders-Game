#pragma once
#include "Entity.h"

class Aliens : public Entity
{
public:
	Aliens() {};
	Aliens(sf::Vector2f pos, sf::Vector2f spd, std::string path);
	void setLives(int liv);
	int  getLives();
	void collide(Entity* e) override;
	void collide(Bullet* e) override;
	void collide(Asteroid* e) override;
	void collide(Spaceship* e) override;
	void collide(Aliens* e) override;
	~Aliens();

private:
	int lives = 1;

};