#pragma once
#include "LevelBuilder.h"
#include "Player.h"
#include "Enemy.h"
#include "Platform.h"
#include "Obstacle.h"

class LevelBuilder1 :
	public LevelBuilder
{
public:
	LevelBuilder1();
	~LevelBuilder1();
	virtual void BuildLevel();
	virtual void BuildPlayer(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildPlayer2(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildEnemy(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void BuildObstacle();
	virtual void BuildBackground(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale);
	virtual void BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile);

	virtual Level* getLevel() { return currentLevel; }
	void load(std::ofstream);

private:
	Level* currentLevel;

	//Macros
	const float WINDOW_WIDHT = 1920.0f;
	const float WINDOW_HEIGHT = 1080.0f;
};