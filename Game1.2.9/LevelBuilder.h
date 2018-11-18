#pragma once
#include "Level.h"

class LevelBuilder
{
public:
	LevelBuilder();
	~LevelBuilder();
	virtual void BuildLevel();
	virtual void BuildPlayer(sf::Vector2f position, sf::Vector2f size) {}
	virtual void BuildPlayer2(sf::Vector2f position, sf::Vector2f size) {}
	virtual void BuildEnemy(sf::Vector2f position, sf::Vector2f size) {}
	virtual void BuildEnemy2(sf::Vector2f position, sf::Vector2f size, const float pos1, const float pos2) {}
	virtual void BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void BuildBackground(sf::Vector2f position, sf::Vector2f size) {}
	virtual void BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale) {}
	virtual void BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile) {}

	virtual Level* getLevel();
};