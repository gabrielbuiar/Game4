#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Animator
{
public:
	Animator(float switchTime = 0);
	~Animator();
	void InitializeAnim(sf::Vector2u imgCount, float switchTime);
	sf::IntRect UpdateAnimator(const char* textureFile, bool faceRight, float deltaTime);
	void setTexture(const char* textureFile);

private:
	sf::Vector2u imgCount;
	sf::Vector2u currImg;
	sf::IntRect uvRect;

	float totalTime = 0;
	float switchTime;
	bool faceRight;

};