#include "Obstacle.h"



Obstacle::Obstacle(const char* textureFile)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	InitializeObstacle(position, size, textureFile);
}


Obstacle::~Obstacle()
{
}

void Obstacle::InitializeObstacle(sf::Vector2f position, sf::Vector2f size, const char * textureFile)
{
	InitializeEnt(position, size, textureFile);
}
