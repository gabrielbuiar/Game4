#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Enemy();
	void InitializeEnemy(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
	void calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	void calcMovement(const float deltaTime, sf::Vector2f position1);
	virtual void Update(float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	virtual void Update(float deltaTime, sf::Vector2f position1);
	virtual void draw(sf::RenderWindow& window);
	void setKillPoints(unsigned int points) { killPoints = points; }
	const unsigned int getKillPoints() { return killPoints; }
	void save(std::ofstream& Save) { Save << id << ' ' << base.getPosition().x << ' ' << base.getPosition().y << ' ' << base.getSize().x << ' ' << base.getSize().y << ' ' << life << std::endl; }

private:
	unsigned int killPoints = 0;

};
