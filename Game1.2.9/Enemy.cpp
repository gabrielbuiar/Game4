#include "Enemy.h"

Enemy::Enemy(const char* textureFile, float speed, float jumpHeight)
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

	InitializeEnemy(position, size, textureFile, imgCount, speed, jumpHeight);
}

Enemy::~Enemy()
{
}

void Enemy::InitializeEnemy(sf::Vector2f position, sf::Vector2f size, const char * textureFile, sf::Vector2u imgCount, float speed, float jumpHeight)
{
	InitializeChar(position, size, textureFile, imgCount, speed, jumpHeight);
	row = 0;
}

void Enemy::calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
{
	sf::Vector2f other, position;
	float diff1, diff2;


	position = getPosition();

	diff1 = sqrt(((position1.x  - position.x ) * (position1.x - position.x)) + ((position1.y - position.y) * (position1.y - position.y)));
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

	if ((other.y - 10.f > position.y) && canJump)
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

void Enemy::calcMovement(const float deltaTime, sf::Vector2f position1)
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

	if ((other.y - 10.f > position.y) && canJump)
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

void Enemy::Update(float deltaTime, sf::Vector2f position1, sf::Vector2f position2)
{
	if (life <= 0)
	{
		life = 0;
		dead = true;
	}

	LifePct = float(life) / float(lifei);
	calcMovement(deltaTime, position1, position2);
	textureFile = getTextureFile(row);
	animator.InitializeAnim(sf::Vector2u(getImgCount(row), 1), 1.0f / getImgCount(row));
	animator.setTexture(textureFile);
	setTexture(textureFile);
	base.setTextureRect(animator.UpdateAnimator(textureFile, faceRight, deltaTime));
	base.move(velocity * deltaTime);
}

void Enemy::Update(float deltaTime, sf::Vector2f position1)
{
	if (life <= 0)
	{
		life = 0;
		dead = true;
	}

	LifePct = float(life) / float(lifei);

	calcMovement(deltaTime, position1);
	textureFile = getTextureFile(row);
	animator.InitializeAnim(sf::Vector2u(getImgCount(row), 1), 1.0f / getImgCount(row));
	animator.setTexture(textureFile);
	setTexture(textureFile);
	base.setTextureRect(animator.UpdateAnimator(textureFile, faceRight, deltaTime));
	base.move(velocity * deltaTime);
}

void Enemy::draw(sf::RenderWindow & window)
{
	if (!dead)
		window.draw(base);

	sf::VertexArray quad(sf::Quads, 4);


	/*quad[0].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - 50, window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 65.f);
	quad[1].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (350 * LifePct) - 50, window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 65.f);
	quad[2].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - (350 * LifePct) - 50, window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 80.f);
	quad[3].position = sf::Vector2f(window.getView().getCenter().x + (window.getView().getSize().x / 2.f) - 50, window.getView().getCenter().y - (window.getView().getSize().y / 2.f) + 80.f);*/

	quad[0].position = sf::Vector2f(getPosition().x - 45, getPosition().y - 78.f);
	quad[1].position = sf::Vector2f(getPosition().x - 45 + (88 * LifePct), getPosition().y - 78.f);
	quad[2].position = sf::Vector2f(getPosition().x - 45 + (88 * LifePct), getPosition().y - 83.f);
	quad[3].position = sf::Vector2f(getPosition().x - 45, getPosition().y - 83.f);

	quad[0].color = sf::Color::Red;
	quad[2].color = sf::Color(static_cast<sf::Uint8> (255 * (1.0f - LifePct)), static_cast <sf::Uint8> (255 * LifePct), 0, 255);
	quad[1].color = sf::Color(static_cast<sf::Uint8> (255 * (1.0f - LifePct)), static_cast <sf::Uint8> (255 * LifePct), 0, 255);
	quad[3].color = sf::Color::Red;

	window.draw(quad);
}
