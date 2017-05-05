#pragma once
#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid();
	Asteroid(sf::Vector2f pos, std::string path);
	void collide(Entity* e) override;
	void collide(Bullet* e) override;
	void collide(Asteroid* e) override;
	void collide(Spaceship* e) override;
	void collide(Aliens* e) override;
	~Asteroid();

private:

};