#include "Entity.h"
#include "iostream"



Entity::Entity(const char * textureFile)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	InitializeEnt(position, size, textureFile);
}


Entity::~Entity()
{
}

void Entity::InitializeEnt(sf::Vector2f position, sf::Vector2f size, const char * textureFile)
{
	base.setSize(size);
	base.setPosition(position);
	base.setOrigin(size / 2.0f);
	setTexture(textureFile);
	if (textureFile != NULL)
		strcpy_s(this->textureFile, textureFile);
}

void Entity::Draw(sf::RenderWindow* window)
{
	window->draw(base);
}

void Entity::setTexture(const char * textureFile)
{
	if (textureFile != NULL)
	{
		texture.loadFromFile(textureFile);
		base.setTexture(&texture);
	}
}

bool Entity::checkCollision(Entity & other, sf::Vector2f & direction, float push)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfPosition = other.getHalfPosition();
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfPosition = getHalfPosition();
	sf::Vector2f intersection;

	float dx = otherPosition.x - thisPosition.x;
	float dy = otherPosition.y - thisPosition.y;

	intersection.x = abs(dx) - (otherHalfPosition.x + thisHalfPosition.x);
	intersection.y = abs(dy) - (otherHalfPosition.y + thisHalfPosition.y);

	if (intersection.x < 0.0f && intersection.y < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersection.x > intersection.y)
		{
			if (dx > 0.0f)
			{
				move(intersection.x * (1.0f - push), 0.0f);
				other.move(-intersection.x * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;
			}
			else
			{
				move(-intersection.x * (1.0f - push), 0.0f);
				other.move(intersection.x * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (dy > 0.0f)
			{
				move(0.0f, intersection.y * (1.0f - push));
				other.move(0.0f, -intersection.y * push);

				direction.x = 0.0f;
				direction.y = -1.0f;
			}
			else
			{
				move(0.0f, -intersection.y * (1.0f - push));
				other.move(0.0f, intersection.y * push);

				direction.x = 0.0f;
				direction.y = 1.0f;
			}
		}

		return true;
	}

	return false;
}
