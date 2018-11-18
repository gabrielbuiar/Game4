#include "Animator.h"



Animator::Animator(float switchTime)
{
	sf::Vector2u imgCount;
	imgCount.x = 0;
	imgCount.y = 0;

	currImg.x = 0;
	currImg.y = 0;

	InitializeAnim(imgCount, switchTime);
}


Animator::~Animator()
{
}

void Animator::InitializeAnim(sf::Vector2u imgCount, float switchTime)
{
	this->switchTime = switchTime;
	this->imgCount = imgCount;
}

sf::IntRect Animator::UpdateAnimator(const char* textureFile, bool faceRight, float deltaTime)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currImg.x++;

		if (currImg.x >= imgCount.x)
			currImg.x = 0;
	}
	if (faceRight)
	{
		uvRect.left = currImg.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currImg.x + 1)* abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	uvRect.top = currImg.y * uvRect.height;

	return uvRect;
}

void Animator::setTexture(const char * textureFile)
{
	if (textureFile != NULL)
	{
		sf::Texture texture;
		texture.loadFromFile(textureFile);
		uvRect.width = int(texture.getSize().x / float(imgCount.x));
		uvRect.height = int(texture.getSize().y);
	}
}
