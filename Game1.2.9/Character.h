#pragma once
#include "Entity.h"
#include "Animator.h"
#include <iostream>
#include <vector>

class Character :
	public Entity
{
public:
	Character(const char* textureFile = NULL, const float deltaTime = 0, const float speed = 0, const float jumpHeight = 0);
	~Character();
	void InitializeChar(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, const float speed, const float jumpHeight);
	//void setTexture(const char* textureFile);
	virtual void Update(float deltaTime);
	virtual void draw(sf::RenderWindow& window);
	virtual void calcMovement(const float deltaTime) { std::cout << "1" << std::endl; }
	void SetTexture();
	void onCollision(sf::Vector2f direction);
	void includeTextureVector(char* file) { textureVector.push_back(file); }
	void includeImgCountVector(unsigned int count) { imgCountVector.push_back(count); }
	char* getTextureFile(unsigned int it) { return textureVector[it]; }
	unsigned int getImgCount(unsigned int it) { return imgCountVector[it]; }
	void setLife(const unsigned int life) { this->life = life; }
	void setDamage(const unsigned int damage) { this->damage = damage; }
	void operator-=(const unsigned int damage) { life -= damage; }
	const bool Dead() { return dead; }
	const bool getfaceRight() { return faceRight; }
	const unsigned int getDamage() { return damage; }
	void setPositionx(const float positionx) { base.setPosition(positionx, base.getPosition().y); }
	const unsigned int getLife() { return life; }

protected:
	Animator animator;
	float speed;
	bool faceRight;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	unsigned int row;
	const char* textureFile;
	float switchTime;
	float deltaTime;
	std::vector<char*> textureVector;
	std::vector<unsigned int> imgCountVector;
	int life;
	unsigned int damage;
	unsigned int lifei;
	float LifePct = 1.0f;
	bool dead = false;

};
