#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(sf::Vector2f pos, sf::Vector2f spd, std::string path)
	:position(pos), speed(spd), isAlive(true)
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

void Entity::moveUp()
{
	position.y = position.y - speed.y;
	sprite.setPosition(position);
}
void Entity::moveDown()
{
	position.y = position.y + speed.y;
	sprite.setPosition(position);
}
void Entity::moveLeft() 
{
	position.x = position.x - speed.x;
	sprite.setPosition(position);
}
void Entity::moveRight()
{
	position.x = position.x + speed.x;
	sprite.setPosition(position);
}
void Entity::kill()
{
	isAlive = false;
}
bool Entity::getIsAlive()
{
	return isAlive;
}
void Entity::respawn()
{
	isAlive = true;
}
void Entity::setLocation(sf::Vector2f loc)
{
	sprite.setPosition(loc.x,loc.y);
}
void Entity::draw(sf::RenderWindow &win)
{
	sprite.setTexture(texture);
	win.draw(sprite);
}
sf::Sprite& Entity::getSprite()
{
	return sprite;
}
sf::Texture& Entity::getTexture()
{
	return texture;
}

bool Entity::doesCollide(Entity* e)
{
	sf::FloatRect minRect = sprite.getGlobalBounds();
	sf::FloatRect entRect = e->sprite.getGlobalBounds();
	bool collide = minRect.intersects(entRect);
	return collide;
}