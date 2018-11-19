#include "Obstacle1.h"



Obstacle1::Obstacle1()
{
}


Obstacle1::~Obstacle1()
{
	bullets.clear();
}

void Obstacle1::Update(const float deltaTime)
{
	int i = 0;

	if (activated)
	{
		if (!delay)
		{
			sf::RectangleShape* pAux = new sf::RectangleShape;
			pAux->setPosition(base.getPosition().x, base.getPosition().y - 15.f);
			pAux->setSize(sf::Vector2f(10.5f, 3.f));
			pAux->setFillColor(sf::Color(222, 176, 0));
			bullets.push_back(pAux);
		}
		delay++;
		if (delay >= 10)
			delay = 0;
	}

	while ( i < bullets.size())
	{
		bullets[i]->move(sf::Vector2f(bulletSpeed * deltaTime, 0));
		i++;
	}

	totalTime += deltaTime;

	if (totalTime > activatedTime && activated)
	{
		totalTime -= activatedTime;
		activated = false;
	}

	if (totalTime > notActivatedTime && !activated)
	{
		totalTime -= notActivatedTime;
		activated = true;
	}
}

void Obstacle1::draw(sf::RenderWindow & window)
{

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(*bullets[i]);
	}
	window.draw(base);
}

bool Obstacle1::bulletCheckCollision(Entity & other, sf::RectangleShape paux)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfPosition = other.getHalfPosition();
	sf::Vector2f thisPosition = paux.getPosition();
	sf::Vector2f thisHalfPosition = sf::Vector2f(paux.getSize().x / 2.f, paux.getSize().y / 2.f);
	sf::Vector2f intersection;

	float dx = otherPosition.x - thisPosition.x;
	float dy = otherPosition.y - thisPosition.y;

	intersection.x = abs(dx) - (otherHalfPosition.x + thisHalfPosition.x);
	intersection.y = abs(dy) - (otherHalfPosition.y + thisHalfPosition.y);

	if (intersection.x < 0.0f && intersection.y < 0.0f)
	{
		return true;
	}

	return false;
}

bool Obstacle1::bulletCheckCollision(Character & other, sf::RectangleShape paux)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfPosition = other.getHalfPosition();
	sf::Vector2f thisPosition = paux.getPosition();
	sf::Vector2f thisHalfPosition = sf::Vector2f(paux.getSize().x / 2.f, paux.getSize().y / 2.f);
	sf::Vector2f intersection;

	float dx = otherPosition.x - thisPosition.x;
	float dy = otherPosition.y - thisPosition.y;

	intersection.x = abs(dx) - (otherHalfPosition.x + thisHalfPosition.x);
	intersection.y = abs(dy) - (otherHalfPosition.y + thisHalfPosition.y);

	if (intersection.x < 0.0f && intersection.y < 0.0f)
	{
		return true;
	}

	return false;
}

bool Obstacle1::checkCollision(Entity& other, sf::Vector2f & direction, float push)
{
	int i = 0;

	for (i = 0; i < bullets.size(); i++)
	{
			if (bulletCheckCollision(other, *(bullets[i])))
			{
				bullets.erase(bullets.begin() + i);
			}
	}
	return false;
}

bool Obstacle1::checkCollision(Character& other, sf::Vector2f & direction, float push)
{
	int i = 0;
	for (i = 0; i < bullets.size() ; i++)
	{

		if (bulletCheckCollision(other, *bullets[i]))
		{
			other.operator-=(bulletDamage);
			bullets.erase(bullets.begin() + i);
		}
	}

	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfPosition = other.getHalfPosition();
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfPosition = getHalfPosition();
	sf::Vector2f intersection;

	float dx = otherPosition.x - thisPosition.x;
	float dy = otherPosition.y - thisPosition.y;

	intersection.x = abs(dx) - (otherHalfPosition.x + thisHalfPosition.x);
	intersection.y = abs(dy) - (otherHalfPosition.y + thisHalfPosition.y);

	if (intersection.x < 0.0f && intersection.y < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersection.x > intersection.y)
		{
			if (dx > 0.0f)
			{
				move(intersection.x * (1.0f - push), 0.0f);
				other.move(-intersection.x * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;
			}
			else
			{
				move(-intersection.x * (1.0f - push), 0.0f);
				other.move(intersection.x * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (dy > 0.0f)
			{
				move(0.0f, intersection.y * (1.0f - push));
				other.move(0.0f, -intersection.y * push);

				direction.x = 0.0f;
				direction.y = -1.0f;
			}
			else
			{
				move(0.0f, -intersection.y * (1.0f - push));
				other.move(0.0f, intersection.y * push);

				direction.x = 0.0f;
				direction.y = 1.0f;
			}
		}

		return true;
	}

	return false;
}
