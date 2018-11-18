#include "Enemy1.h"



Enemy1::Enemy1(const char * textureFile, float speed, float jumpHeight)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	sf::Vector2u imgCount;
	imgCount.x = 0;
	imgCount.y = 0;

	InitializeEnemy1(position, size, textureFile, imgCount, speed, jumpHeight);
}

Enemy1::~Enemy1()
{
}

void Enemy1::InitializeEnemy1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	InitializeEnemy(position, size, textureFile, imgCount, speed, jumpHeight);
	row = 0;
}

void Enemy1::calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
{
	sf::Vector2f other, position;
	float diff1, diff2;


	position = getPosition();

	diff1 = sqrt(((position1.x - position.x) * (position1.x - position.x)) + ((position1.y - position.y) * (position1.y - position.y)));
	diff2 = sqrt(((position2.x - position.x) * (position2.x - position.x)) + ((position2.y - position.y) * (position2.y - position.y)));

	if (diff1 <= diff2)
		other = position1;
	else
		other = position2;

	velocity.x = 0.0f;

	if (other.x < position.x)
	{
		velocity.x -= speed;
	}
	if (other.x > position.x)
	{
		velocity.x += speed;
	}

	if ((other.y + 30.f < position.y) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x != 0.f)
	{
		if (velocity.x > 0.f)
			faceRight = true;
		else
			faceRight = false;
	}
	row = 0;
}

void Enemy1::calcMovement(const float deltaTime, sf::Vector2f position1)
{
	sf::Vector2f other, position;

	other = position1;
	position = getPosition();

	velocity.x = 0.0f;

	if (other.x < position.x)
	{
		velocity.x -= speed;
	}
	if (other.x > position.x)
	{
		velocity.x += speed;
	}

	if ((other.y + 30.f < position.y) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x != 0.f)
	{
		if (velocity.x > 0.f)
			faceRight = true;
		else
			faceRight = false;
	}
	row = 0;
}
