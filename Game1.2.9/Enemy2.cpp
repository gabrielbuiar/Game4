#include "Enemy2.h"



Enemy2::Enemy2(const char * textureFile, float speed, float jumpHeight)
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

	float pos1, pos2;
	pos1 = 0.f;
	pos2 = 0.f;

	InitializeEnemy2(position, size, textureFile, imgCount, speed, jumpHeight, pos1, pos2);
}


Enemy2::~Enemy2()
{
}

void Enemy2::InitializeEnemy2(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight, float pos1, float pos2)
{
	InitializeEnemy(position, size, textureFile, imgCount, speed, jumpHeight);

	if (pos1 > pos2)
	{
		float aux;
		aux = pos1;
		pos1 = pos2;
		pos2 = aux;
	}

	this->pos1 = pos1;
	this->pos2 = pos2;

	row = 0;
}

void Enemy2::calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
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

	if (pos2 < position.x)
	{
		velocity.x -= speed;
	}
	else if (pos1 > position.x)
		velocity.x += speed;
	else if (faceRight)
		velocity.x += speed;
	else
		velocity.x -= speed;

	if ((other.y + 70.f < position.y) && canJump)
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

void Enemy2::calcMovement(const float deltaTime, sf::Vector2f position1)
{
	sf::Vector2f other, position;

	other = position1;
	position = getPosition();

	velocity.x = 0.0f;

	if (pos2 < position.x)
	{
		velocity.x -= speed;
	}
	else if (pos1 > position.x)
		velocity.x += speed;
	else if (faceRight)
		velocity.x += speed;
	else
		velocity.x -= speed;

	if ((other.y + 70.f < position.y) && canJump)
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
