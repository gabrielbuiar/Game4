#pragma once
#include "Entity.h"
class Platform : public Entity
{
public:
	Platform(const char* textureFile = NULL);
	~Platform();
	void InitializePlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
};
