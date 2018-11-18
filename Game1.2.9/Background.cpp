#include "Background.h"



Background::Background(const char* textureFile, const float increment, const float incrementScale) :
	Entity(textureFile)
{
	sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f size = sf::Vector2f(0.0f, 0.0f);

	Initialize(position, size, textureFile, increment, incrementScale);
}


Background::~Background()
{
}

void Background::Initialize(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale)
{
	InitializeEnt(position, size, textureFile);
	this->position = position;
	this->size = size;
	setTexture(textureFile);
	this->increment = increment;
	this->incrementScale = incrementScale;
	this->inc = increment;
	iposition = this->position;
	increment0 = increment;
	incrementScale0 = incrementScale;
}

void Background::setTexture(const char * textureFile)
{
	if (textureFile != NULL)
	{
		texture.loadFromFile(textureFile);
		back.setTexture(texture);
		back.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);
		back.setPosition(position);
	}
}

void Background::move(sf::Vector2f playerPosition, float speed)
{
		if (speed != 0 && !stand)
		{
			if (speed <= 0)
				incrementScale = -abs(incrementScale);
			else
				incrementScale = abs(incrementScale);
			increment += inc * incrementScale;
			position.x = playerPosition.x + increment + iposition.x;
			back.setPosition(position);
		}
}
