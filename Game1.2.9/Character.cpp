#include "Character.h"



Character::Character(const char* textureFile, const float deltaTime, const float speed, const float jumpHeight)
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

	InitializeChar(position, size, textureFile, imgCount, speed, jumpHeight);
}


Character::~Character()
{
	textureVector.clear();
	imgCountVector.clear();
}

void Character::InitializeChar(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, const float speed, const float jumpHeight)
{
	InitializeEnt(position, size, textureFile);
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->textureFile = textureFile;
	switchTime = 1.0f / float(imgCount.x);
	faceRight = true;
	this->deltaTime = deltaTime;
	animator.InitializeAnim(imgCount, switchTime);
	animator.setTexture(textureFile);
	lifei = life;
}

void Character::Update(float deltaTime)
{
	if (life <= 0)
	{
		life = 0;
		dead = true;
	}

	LifePct = float(life) / float(lifei);

	calcMovement(deltaTime);
	textureFile = getTextureFile(row);
	animator.InitializeAnim(sf::Vector2u(getImgCount(row), 1), 1.0f / getImgCount(row));
	animator.setTexture(textureFile);
	setTexture(textureFile);
	base.setTextureRect(animator.UpdateAnimator(textureFile, faceRight, deltaTime));
	base.move(velocity * deltaTime);

}

void Character::draw(sf::RenderWindow& window)
{
	if (!dead)
		window.draw(base);

	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(getPosition().x - 43.f, -100.f + getPosition().y);
	quad[1].position = sf::Vector2f(getPosition().x - 43.f + (88.f * LifePct), -100.f + getPosition().y);
	quad[2].position = sf::Vector2f(getPosition().x - 43.f + (88.f * LifePct), -110.f + getPosition().y);
	quad[3].position = sf::Vector2f(getPosition().x - 43.f, -110.f + getPosition().y);

	quad[0].color = sf::Color::Red;
	quad[2].color = sf::Color(static_cast<sf::Uint8> (255 * (1.0f - LifePct)), static_cast < sf::Uint8> (255 * LifePct), 0, 255);
	quad[1].color = sf::Color(static_cast<sf::Uint8> (255 * (1.0f - LifePct)), static_cast <sf::Uint8> (255 * LifePct), 0, 255);
	quad[3].color = sf::Color::Red;

	window.draw(quad);
}

void Character::SetTexture()
{
	animator.setTexture(textureFile);
}

void Character::onCollision(sf::Vector2f direction)
{
	if (direction.x != 0)
	{
		if (direction.x < 0.0f)
		{
			velocity.x = 0.0f;
		}
		else if (direction.x > 0.0f)
		{
			velocity.x = 0.0f;
		}
	}
	if (direction.y != 0)
	{
		if (direction.y < 0.0f)
		{
			velocity.y = 0.0f;
		}
		else if (direction.y > 0.0f)
		{
			velocity.y = 0.0f;
			canJump = true;
		}
	}	
}
