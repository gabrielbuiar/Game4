#pragma once
#include "Level.h"

class LevelBuilder
{
public:
	LevelBuilder() {};
	~LevelBuilder() {};
	virtual void BuildLevel() = 0;
	virtual void BuildPlayer(sf::Vector2f position, sf::Vector2f size) = 0;
	virtual void BuildPlayer2(sf::Vector2f position, sf::Vector2f size) = 0;
	virtual void BuildEnemy(sf::Vector2f position, sf::Vector2f size) = 0;
	virtual void BuildEnemy2(sf::Vector2f position, sf::Vector2f size, const float pos1, const float pos2) = 0;
	virtual void BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile) = 0;
	virtual void BuildBackground(sf::Vector2f position, sf::Vector2f size) = 0;
	virtual void BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale) = 0;
	virtual void BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile) = 0;
	virtual void BuildObstacle(sf::Vector2f position, sf::Vector2f size) = 0;
	virtual void BuildObstacle_1(sf::Vector2f position, sf::Vector2f size, const float bulletSpeed, const float bulletDamage) = 0;

	virtual Level* getLevel() = 0;
};