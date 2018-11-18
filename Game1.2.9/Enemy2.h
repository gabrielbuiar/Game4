#pragma once
#include "Enemy.h"

class Enemy2 :
	public Enemy
{
public:
	Enemy2(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Enemy2();
	void InitializeEnemy2(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight, float pos1, float pos2);
	virtual void calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	virtual void calcMovement(const float deltaTime, sf::Vector2f position1);
	virtual void save(std::ofstream& Save) { Save << id << ' ' << base.getPosition().x << ' ' << base.getPosition().y << ' ' << base.getSize().x << ' ' << base.getSize().y << ' ' << pos1 << ' ' << pos2 << ' ' << life << ' ' << std::endl; }

private:
	float pos1;
	float pos2;
};