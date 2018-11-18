#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
public:
	Obstacle(const char* textureFile = NULL);
	~Obstacle();
	void InitializeObstacle(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
};

