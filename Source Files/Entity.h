#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Bullet;
class Asteroid;
class Spaceship;
class Aliens;

class Entity
{
public:
	Entity();
	Entity(sf::Vector2f pos, sf::Vector2f spd, std::string path);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void kill();
	bool getIsAlive();
	void respawn();
	void setLocation(sf::Vector2f);
	void draw(sf::RenderWindow &win);

	sf::Sprite& getSprite();
	sf::Texture& getTexture();

	bool doesCollide(Entity* e);
	virtual void collide(Entity* e) = 0;
	virtual void collide(Bullet* e) = 0;
	virtual void collide(Asteroid* e) = 0;
	virtual void collide(Spaceship* e) = 0;
	virtual void collide(Aliens* e) = 0;
	virtual ~Entity() {}

private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;

	sf::Vector2f speed;
	bool isAlive;
};
