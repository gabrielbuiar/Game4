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
	virtual void BuildPlayer(sf::Vector2f position, sf::Vector2f size, const unsigned int life, const unsigned int points);
	virtual void BuildPlayer2(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildPlayer2(sf::Vector2f position, sf::Vector2f size, const unsigned int life, const unsigned int points);


	virtual void BuildEnemy(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildEnemy(sf::Vector2f position, sf::Vector2f size, const unsigned int life);
	virtual void BuildEnemy2(sf::Vector2f position, sf::Vector2f size, const float pos1, const float pos2);
	virtual void BuildEnemy2(sf::Vector2f position, sf::Vector2f size, const float pos1, const float pos2, const unsigned int life);


	virtual void BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile);


	virtual void BuildObstacle();


	virtual void BuildBackground(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale);
	virtual void BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile);



	virtual std::streampos LoadPlayer(std::streampos str);
	virtual std::streampos LoadPlayer2(std::streampos str);


	virtual std::streampos LoadEnemy(std::streampos str);
	virtual std::streampos LoadEnemy2(std::streampos str);

	virtual std::streampos LoadPlatform(std::streampos str);


	virtual std::streampos LoadObstacle(std::streampos str) { return NULL; }


	virtual std::streampos LoadBackground(std::streampos str);
	virtual std::streampos LoadBackground_1(std::streampos str);
	virtual std::streampos LoadBackground_2(std::streampos str);



	virtual Level* getLevel() { return currentLevel; }
	void load(std::streampos str);

private:
	Level* currentLevel;

	//Macros
	const float WINDOW_WIDHT = 1920.0f;
	const float WINDOW_HEIGHT = 1080.0f;
};