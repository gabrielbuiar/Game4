#pragma once
#include "Enemy.h"

class Enemy1 :
	public Enemy
{
public:
	Enemy1(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Enemy1();
	void InitializeEnemy1(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
	void calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	void calcMovement(const float deltaTime, sf::Vector2f position1);

};

