#include "Platform.h"



Platform::Platform(const char* textureFile)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	InitializePlatform(position, size, textureFile);
}


Platform::~Platform()
{
}

void Platform::InitializePlatform(sf::Vector2f position, sf::Vector2f size, const char * textureFile)
{
	InitializeEnt(position, size, textureFile);
}
